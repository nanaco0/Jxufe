USE master

-----------------↓创建数据库↓-----------------

CREATE DATABASE WareDB
on(
  name='WareDB',
  filename='D:\Document_user\SQL\Document\WareDB\WareDB.mdf',
  size=3,
  maxsize=20,
  filegrowth=1)
log on
 (name='WareDB',
  filename='D:\Document_user\SQL\Document\WareDB\WareDB_Log.ldf',
  size=1,
  maxsize=5,
  filegrowth=1)
GO


-----------------↓创建表及主键、外键、CHECK↓-----------------
USE WareDB

CREATE TABLE Administrator (
	administratorNo			char(10)			NOT NULL,
	administratorName		varchar(20)			NOT NULL,
	sex						char(2)				NULL,
	identitycard			char(18)	UNIQUE	NOT NULL,
	administratorPhoneNo	char(11)			NOT NULL,
	rootAdministrator		char(2)				NOT NULL,
	adPassWord				char(10)			NOT NULL,
	CONSTRAINT PK_Administrator PRIMARY KEY (administratorNo),
	CONSTRAINT CK_rootAdministrator CHECK (rootAdministrator IN ('是', '否')),
	CONSTRAINT CK_sex CHECK (sex IN ('男', '女')),
	CONSTRAINT CK_adPassWord CHECK (LEN(AdPassWord) >= 6)
)
PRINT 'The Administrator table has been created.'
GO

CREATE TABLE Supplier (
	supplierNo		char(8)		NOT NULL,
	supplierName	varchar(10)	NOT NULL,
	supplierPhoneNo	char(11)	NOT NULL,
	supplierAddress	varchar(60)	NULL,
	CONSTRAINT PK_Supplier PRIMARY KEY (supplierNo)
)
PRINT 'The Supplier table has been created.'
GO

CREATE TABLE CheckIn (
	checkInNo		char(10)							NOT NULL,
	checkInTime		smalldatetime	DEFAULT GETDATE()	NOT NULL,
	administratorNo	char(10)							NOT NULL,
	CONSTRAINT PK_CheckIn PRIMARY KEY (checkInNo),
	CONSTRAINT FK_CheckIn FOREIGN KEY (administratorNo) REFERENCES Administrator(administratorNo),
	CONSTRAINT CK_checkInNo CHECK 
		(checkInNo LIKE 'I' + RIGHT(YEAR(GETDATE()), 2) + RIGHT('0' + CAST(MONTH(GETDATE()) AS VARCHAR(2)), 2) + RIGHT('0' + CAST(DAY(GETDATE()) AS VARCHAR(2)), 2) + '[0-9][0-9][0-9]')
)
PRINT 'The CheckIn table has been created.'
GO

CREATE TABLE CheckInDetails (
	checkInDetailsNo	char(3)		NOT NULL,
	checkInNo			char(10)	NOT NULL,
	wareNo				char(10)	NOT NULL,
	checkInQuantity		int			NOT NULL,
	supplierNo			char(8)		NOT NULL,
	CONSTRAINT PK_CheckInDetails PRIMARY KEY CLUSTERED (checkInDetailsNo,checkInNo),
	CONSTRAINT FK1_CheckInDetails FOREIGN KEY (checkInNo) REFERENCES CheckIn(checkInNo),
	CONSTRAINT FK2_CheckInDetails FOREIGN KEY (supplierNo) REFERENCES Supplier(supplierNo),
	CONSTRAINT CK_checkInDetailsNo CHECK (checkInDetailsNo LIKE '[0-9][0-9][0-9]')	
)
PRINT 'The CheckInDetails table has been created.'
GO

CREATE TABLE CheckOut (
	checkOutNo		char(10)							NOT NULL,
	checkOutTime	smalldatetime	DEFAULT GETDATE()	NOT NULL,
	administratorNo	char(10)							NOT NULL,
	CONSTRAINT PK_CheckOut PRIMARY KEY (checkOutNo),
	CONSTRAINT FK_CheckOut FOREIGN KEY (administratorNo) REFERENCES Administrator(administratorNo),
	CONSTRAINT CK_checkOutNo CHECK 
		(checkOutNo LIKE 'O' + RIGHT(YEAR(GETDATE()), 2) + RIGHT('0' + CAST(MONTH(GETDATE()) AS VARCHAR(2)), 2) + RIGHT('0' + CAST(DAY(GETDATE()) AS VARCHAR(2)), 2) + '[0-9][0-9][0-9]')
)
PRINT 'The CheckOut table has been created.'
GO

CREATE TABLE CheckOutDetails (
	checkOutDetailsNo	char(3)		NOT NULL,
	checkOutNo			char(10)	NOT NULL,
	wareNo				char(10)	NOT NULL,
	checkOutQuantity	int			NOT NULL,
	CONSTRAINT PK_CheckOutDetails PRIMARY KEY CLUSTERED (checkOutDetailsNo,checkOutNo),
	CONSTRAINT FK_CheckOutDetails FOREIGN KEY (checkOutNo) REFERENCES CheckOut(checkOutNo),
	CONSTRAINT CK_checkOutDetailsNo CHECK (checkOutDetailsNo LIKE '[0-9][0-9][0-9]'),
)
PRINT 'The CheckOutDetails table has been created.'
GO

CREATE TABLE WareClass (
	classNo		char(3)		NOT NULL,
	className	varchar(20)	NOT NULL,
	CONSTRAINT PK_WareClass PRIMARY KEY (classNo),
	CONSTRAINT CK_ClassNo CHECK (classNo LIKE '[0-9][0-9][0-9]'),
)
PRINT 'The WareClass table has been created.'
GO

CREATE TABLE Ware (
	wareNo			char(10)	NOT NULL,
	wareName		varchar(20)	NOT NULL,
	wareQuantity	int			NOT NULL,
	classNo			char(3)		NOT NULL,
	wareLocation	char(8)		NOT NULL,
	shelfLife		char(2)		NOT NULL,
	productionDate	datetime	NOT NULL,
	dueDate			datetime	NOT NULL,
	supplierNo		char(8)		NOT NULL,
	CONSTRAINT PK_Ware PRIMARY KEY (wareNo),
	CONSTRAINT FK1_Ware FOREIGN KEY (classNo) REFERENCES WareClass(classNo),
	CONSTRAINT FK2_Ware FOREIGN KEY (supplierNo) REFERENCES Supplier(supplierNo),
	CONSTRAINT CK_WareNo CHECK (WareNo LIKE '[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]')
)
PRINT 'The Ware table has been created.'
GO


-----------------↓完整性设计↓-----------------

--入库数量更新触发器
USE WareDB
GO

CREATE TRIGGER checkIn_ware_quantity
ON CheckInDetails
AFTER INSERT
AS
BEGIN
  DECLARE @checkInQuantity INT;
  DECLARE @wareNo INT;

  SELECT @checkInQuantity = inserted.checkInQuantity, @wareNo = inserted.wareNo
  FROM inserted;

  UPDATE Ware 
  SET wareQuantity = wareQuantity + @checkInQuantity
  WHERE wareNo = @wareNo;

  PRINT '入库数量为' + CAST(@checkInQuantity AS VARCHAR(MAX)) + '，wareQuantity的数值已更新';
END;
GO

--出库数量更新触发器
USE WareDB
GO

CREATE TRIGGER checkOut_ware_quantity
ON CheckOutDetails
AFTER INSERT
AS
BEGIN
  SET NOCOUNT ON;
  
  DECLARE @checkOutQuantity int, @wareNo int, @wareQuantity int;
  
  SELECT @checkOutQuantity = checkOutQuantity, @wareNo = wareNo 
  FROM inserted;
  
  SELECT @wareQuantity = wareQuantity 
  FROM Ware 
  WHERE wareNo = @wareNo;
  
  IF @wareQuantity < @checkOutQuantity
  BEGIN
    ROLLBACK TRANSACTION;
    PRINT '库存不足，出库失败';
  END
  ELSE
  BEGIN
    UPDATE Ware
    SET wareQuantity = wareQuantity - @checkOutQuantity
    WHERE wareNo = @wareNo;
    
    PRINT '出库数量为' + CAST(@checkOutQuantity AS VARCHAR(10)) + '，wareQuantity的数值已更新';
  END
END;
GO

USE WareDB
GO

--低库存触发器
CREATE TRIGGER WareQuantityCheckTrigger
ON Ware
AFTER UPDATE
AS 
BEGIN
    IF EXISTS (SELECT * FROM inserted WHERE wareQuantity < 30)
        BEGIN
            DECLARE @WareName VARCHAR(50)
            SELECT @WareName = wareName FROM inserted
            PRINT '库存警报：商品[' + @WareName + ']库存数量低于30'
        END
END
GO

-- 创建定时任务检查保质期
USE WareDB;

IF OBJECT_ID('dbo.CheckDueDate') IS NOT NULL
    DROP PROCEDURE dbo.CheckDueDate;
GO

CREATE PROCEDURE dbo.CheckDueDate
AS
BEGIN
    SET NOCOUNT ON;

    DECLARE @today DATE = GETDATE();

    SELECT '商品编号：' + wareNo + '，到期日期：' + CONVERT(NVARCHAR(10), dueDate, 120) 
           + '，距离到期还有 ' + CAST(DATEDIFF(day, @today, dueDate) AS NVARCHAR(10)) + ' 天。' 
    FROM Ware
    WHERE DATEDIFF(day, @today, dueDate) < 30;
END;
GO

IF EXISTS (SELECT * FROM msdb.dbo.sysjobs WHERE name = N'CheckDueDate')
BEGIN
    EXEC msdb.dbo.sp_delete_job @job_name = N'CheckDueDate';
END

DECLARE @jobId binary(16);
EXEC msdb.dbo.sp_add_job @job_name=N'CheckDueDate', @enabled=1, @job_id=@jobId OUTPUT;
EXEC msdb.dbo.sp_add_jobstep @job_id=@jobId, @step_name=N'Check Due Date', @subsystem=N'TSQL', 
    @command=N'EXEC dbo.CheckDueDate;', @database_name='WareDB', @retry_attempts=0, @retry_interval=0, @output_file_name=N'NUL', @flags=0;
EXEC msdb.dbo.sp_add_schedule @schedule_name=N'Daily at 10am', @freq_type=4, @freq_interval=1, @freq_subday_type=1, @freq_subday_interval=0, @freq_relative_interval=0, @freq_recurrence_factor=1, @active_start_time=100000, @active_end_time=235959;
EXEC msdb.dbo.sp_attach_schedule @job_name=N'CheckDueDate', @schedule_name=N'Daily at 10am';
EXEC msdb.dbo.sp_add_jobserver @job_name=N'CheckDueDate', @server_name = N'(local)'; 
GO

--根管理员权限触发器
USE WareDB
GO

CREATE TRIGGER CheckRootAdministrator
ON Administrator
FOR INSERT, UPDATE, DELETE
AS
BEGIN
  IF EXISTS (
      SELECT * FROM inserted WHERE rootAdministrator <> '是'
    )
  BEGIN
    ROLLBACK TRANSACTION;
    RAISERROR('无权限', 16, 1);
  END
END
GO

--雇员年龄非法触发器
USE WareDB
GO

CREATE TRIGGER CheckIllegalEmployee
ON Administrator
AFTER INSERT, UPDATE
AS
BEGIN
  IF EXISTS (SELECT * FROM inserted)
  BEGIN
    DECLARE @BirthDate DATE, @Age INT
    SELECT @BirthDate = CONVERT(DATE, SUBSTRING(identitycard, 7, 8), 112) FROM inserted
    
    SELECT @Age = DATEDIFF(YEAR, @BirthDate, GETDATE())
    
    IF @Age < 16
    BEGIN
      RAISERROR('雇员年龄非法！', 16, 1)
      ROLLBACK TRANSACTION
    END
  END
END

-----------------↓安全性设计↓-----------------

/*创建角色r1和r2*/
CREATE ROLE r1;
CREATE ROLE r2;

/*创建用户root作为仓库的根管理员，并赋予r1角色*/
CREATE LOGIN root WITH PASSWORD = '111111';
CREATE USER root FOR LOGIN root;
ALTER ROLE r1 ADD MEMBER root;

/*授予r1角色对仓库数据库中所有表的查询、插入、删除、更新操作的权限,创建表和视图的权限，删除视图的权限，管理所有管理员的权限*/
GRANT SELECT, INSERT, DELETE, UPDATE ON ALL TABLES IN DATABASE TO r1;
GRANT CREATE TABLE, CREATE VIEW TO r1;
GRANT DELETE ON ALL VIEWS IN DATABASE TO r1;
GRANT SELECT, INSERT, DELETE, UPDATE ON Administrator TO r1;

/*创建普通仓库管理员用户并分配给r2角色*/
DECLARE @adminNo NVARCHAR(100);
DECLARE @adPassWord NVARCHAR(100);

DECLARE admin_cursor CURSOR FOR
SELECT administratorNo, adPassWord FROM Administrator WHERE rootAdministrator = ‘否’;

OPEN admin_cursor;
FETCH NEXT FROM admin_cursor INTO @adminNo, @adPassWord;
WHILE @@FETCH_STATUS = 0
BEGIN
    DECLARE @username NVARCHAR(100) = @adminNo;
    DECLARE @password NVARCHAR(100) = @adPassWord;
    EXEC sp_addlogin @username, @password;
    EXEC sp_adduser @username, @username;
    EXEC sp_addrolemember 'r2', @username;
    FETCH NEXT FROM admin_cursor INTO @adminNo, @adPassWord;
END;

CLOSE admin_cursor;
DEALLOCATE admin_cursor;

/*授予r2角色对仓库数据库中除Administrator表以外的表的查询、插入、删除、更新操作的权限：*/
GRANT SELECT, INSERT, DELETE, UPDATE ON ALL TABLES EXCEPT Administrator TO r2;
GRANT CREATE VIEW TO r2;

/*只有根管理员能查看所有管理员信息的视图，仅允许角色r1的成员进行查看操作*/
CREATE VIEW RootAdminView AS
SELECT *
FROM Administrator;
GRANT SELECT ON dbo.RootAdminView TO r1;
REVOKE SELECT ON dbo.RootAdminView FROM PUBLIC; -- 撤销对所有用户的权限

/*只有根管理员能查看所有管理员工作内容（负责的入库单出库单编号）的视图，仅允许角色r1的成员进行查看操作*/
CREATE VIEW AdminWorkView AS
SELECT a.administratorNo, b.checkInNo,b.checkInTime, c.checkOutNo, c.checkOutTime
FROM Administrator a,CheckIn b,CheckOut c
LEFT JOIN CheckIn b ON a.administratorNo = b.administratorNo
LEFT JOIN CheckOut c ON a.administratorNo = c.administratorNo;
GRANT SELECT ON dbo.AdminWorkView TO r1;
REVOKE SELECT ON dbo.AdminWorkView FROM PUBLIC; -- 撤销对所有用户的权限

/*存在出入库记录的货物视图。仅允许角色r1和r2的成员进行查看操作。视图的筛选条件会确保只列出在入库明细或出库明细中存在记录的货物信息。*/
CREATE VIEW WaresView AS
SELECT *
FROM Ware
WHERE wareNo IN (
    SELECT wareNo
    FROM Ware
    WHERE wareNo IN (
        SELECT DISTINCT wareNo
        FROM CheckInDetails
    )
    OR wareNo IN (
        SELECT DISTINCT wareNo
        FROM CheckOutDetails
    )
)
GRANT SELECT ON dbo.WaresView TO r1,r2;



-----------------↓存储过程设计↓-----------------

-- 按月统计入库工作量最大的前3位仓库管理员的入库信息。

CREATE PROCEDURE admin_tot(@month char(2))
AS
BEGIN
    DECLARE @admin_no char(10), @admin_name varchar(20), @work_num int  
    DECLARE @text varchar(100), @count int
    SET  @count=0
    SELECT @text='=======入库工作量最大的前3位仓库管理员的入库信息=========='
    PRINT @text
    SELECT @text='管理员编号          管理员名称            工作量'
    PRINT @text
    DECLARE admin_cur SCROLL CURSOR FOR
	SELECT a.administratorNo, administratorName, count(checkInNo)
	FROM Administrator a, CheckIn b
	WHERE a.administratorNo=b.administratorNo AND substring(checkInNo,4,2)=@month
	GROUP BY a.administratorNo
	ORDER BY count(checkInNo) DESC
    OPEN admin_cur
    FETCH admin_cur INTO @admin_no, @admin_name, @work_num int
    WHILE(@@FETCH_STATUS=0)
    BEGIN
	SELECT @text=@admin_no+'       '+ @admin_name+'       '+CONVERT(char(10),@work_num)
	PRINT @text       
	SET @count=@count+1
	IF @count<3
	    FETCH get_cur INTO @admin_no, @admin_name,@work_num
	ELSE
	    BREAK 
    END
    CLOSE admin_cur
    DEALLOCATE admin_cur
END 
EXEC admin_tot '10'
GO


-- 输出供应货物位于前5名的供应商中的热门的前3种货物的货物编号、货物名称、总入库数量
CREATE PROCEDURE supplier_tot
AS
GEGIN
    DECLARE @ware_no char(10),@ware_name varchar(20),@ware_num int
    DECLARE @text varchar(100),@count int
    SET  @count=0
    SELECT @text='=======货物供应种类前5位的供应商的前3种货物信息============'
    PRINT @text
    SELECT @text='货物编号      货物名称               总入库数量'
    PRINT @text
    DECLARE get_cur SCROLL CURSOR FOR
	SELECT a.wareNo,wareName,sum(checkInQuantity)
	FROM Ware a,CheckInDetails b, ( 
	    SELECT TOP 5 a.suppilerNo,suppilername,sum(checkInQuantity)
	    FROM Supplier a,CheckInDetails b,
	    WHERE a.supplierNo=b.supplierNo
	    GROUP BY a.supplierNo,suppilername
	    ORDER BY sum(checkInQuantity) DESC) c
	WHERE a.wareNo=b.wareNo and a.suppilerNo=c.suppilerNo
	GROUP BY a.wareNo,wareName
	ORDER BY sum(checkInQuantity) DESC
    OPEN get_cur
    FETCH get_cur INTO @ware_no, @ware_name,@ware_num
    WHILE(@@FETCH_STATUS=0)
    BEGIN
	SELECT @text=@ware_no+'       '+ @ware_name+'       '+CONVERT(char(10),@ware_num)
	PRINT @text       
	SET @count=@count+1
	IF @count<3
	    FETCH get_cur INTO @ware_no, @ware_name,@ware_num
	ELSE
	    BREAK 
    END
    CLOSE get_cur
    DEALLOCATE get_cur
END 
EXEC supplier_tot
GO

-- 根据供应商编号按年统计该供应商的供应信息，输出该供应商的名称、地址、手机号，以及所有与该供应商有关的货物入库信息。

CREATE PROCEDURE sup_tot(@supplier_no char(8), @year char(2))
AS
BEGIN
    DECLARE @supplier_name varchar(10), @supplier_addr varchar(60), supplier_phone	char(11) 
    DECLARE @ware_no char(10),@ware_num int
    DECLARE @text varchar(100)
    SELECT @text='====================供应商供应表===================='
    PRINT @text
    SELECT @text='-----------------------------------------------------------------'
    PRINT @text
    SELECT supplierName=@supplier_name, supplierAddress=@supplier_addr, supplierPhoneNo=@supplier_phone
    FROM Supplier
    WHERE supplierNo=@supplier_no
    SELECT @text='供应商名称：' + @supplier_name
    PRINT @text
    SELECT @text='供应商地址：' + @supplier_addr
    PRINT @text
    SELECT @text='供应商手机号：' + @supplier_phone
    PRINT @text
    SELECT @text='-----------------------------------------------------------------'
    PRINT @text
    SELECT @text='货物编号              总数量'
    PRINT @text
    DECLARE ware_cur SCROLL CURSOR FOR
	SELECT wareNo, sum(checkInQuantity)
	FROM Supplier a, CheckInDetails b
	WHERE a.supplierNo=b.supplierNo AND substring(checkInNo,2,2)=@year
	GROUP BY a.supplierNo
    OPEN ware_cur
    FETCH ware_cur INTO @ware_no, @ware_num
    WHILE(@@FETCH_STATUS=0)
    BEGIN
	SELECT @text=@ware_no+'       '+ CONVERT(char(10),@ware_num)
	PRINT @text       
	FETCH get_cur INTO @admin_no, @admin_name,@work_num
    END
    CLOSE ware_cur
    DEALLOCATE ware_cur
END 
EXEC sup_tot '20230001', '23'
GO


-- 仓库管理员查询入库信息，输入货物的货物编号，使用游标返回所有入库信息。逐行显示该货物的货物编号、货物名称、入库时间、入库数量、供应商编号，并统计该货物的入库总数量。

CREATE PROCEDURE GetCheckInInfo @ware_no char(10)
AS
BEGIN
    DECLARE @ware_name varchar(20), @checkIn_time datetime, @checkIn_quantity int, @supplier_no char(8), @total int
    SET @total = 0
    DECLARE checkIn_cur CURSOR FOR
        SELECT a.wareNo, wareName, checkInTime, chickInQuantity, a.supplierNo
        FROM Ware a, CheckIn b, CheckInDetails c
        WHERE a.wareNo=c.wareNo AND b.checkInNo=c.checkInNo AND a.wareNo=@ware_no
    OPEN checkIn_cur
    FETCH checkIn_cur INTO @ware_name, @checkIn_time, @checkIn_quantity, @supplier_no
    WHILE(@@FETCH_STATUS=0)
    BEGIN
        PRINT '货物编号: ' + @ware_no
        PRINT '货物名称: ' + @ware_name
        PRINT '入库时间: ' + CONVERT(varchar(20), @checkIn_time, 120)
        PRINT '入库数量: ' + CONVERT(varchar(10), @checkIn_quantity)
        PRINT '供应商编号: ' + @supplier_no
        PRINT ''
        SET @total = @total + @checkIn_quantity
        FETCH checkIn_cur INTO @ware_name, @checkIn_time, @checkIn_quantity, @supplier_no
    END
    PRINT '该货物的入库总数量: ' + CONVERT(varchar, @total)
    CLOSE checkIn_cur
    DEALLOCATE checkIn_cur
END
EXEC GetCheckInInfo @ware_no = '货物编号'
GO


-- 仓库管理员查询出库信息，输入货物的货物编号，使用游标返回所有出库信息。逐行显示该货物的货物编号、货物名称、出库时间、出库数量，并统计该货物的出库总数量。

CREATE PROCEDURE GetCheckOutInfo @ware_no char(10)
AS
BEGIN
    DECLARE @ware_name varchar(20), @checkOut_time datetime, @checkOut_quantity int, @total int
    SET @total = 0
    DECLARE checkOut_cur CURSOR FOR
        SELECT a.wareNo, wareName, checkOutTime, chickOutQuantity
        FROM Ware a, CheckOut b, CheckOutDetails c
        WHERE a.wareNo=c.wareNo AND b.checkOutNo=c.checkOutNo AND a.wareNo=@ware_no
    OPEN checkOut_cur
    FETCH checkOut_cur INTO @ware_name, @checkOut_time, @checkOut_quantity
    WHILE(@@FETCH_STATUS=0)
    BEGIN
        PRINT '货物编号: ' + @ware_no
        PRINT '货物名称: ' + @ware_name
        PRINT '出库时间: ' + CONVERT(varchar(20), @checkOut_time, 120)
        PRINT '出库数量: ' + CONVERT(varchar(10), @checkOut_quantity)
        PRINT '供应商编号: ' + @supplier_no
        PRINT ''
        SET @total = @total + @checkOut_quantity
        FETCH checkOut_cur INTO @ware_name, @checkOut_time, @checkOut_quantity
    END
    PRINT '该货物的出库总数量: ' + CONVERT(varchar, @total)
    CLOSE checkOut_cur
    DEALLOCATE checkOut_cur
END
EXEC GetCheckOutInfo @ware_no = '货物编号'
GO


-- 统计货物的入库和出库数量之比来分析货物周转率。

CREATE PROCEDURE wareRate(@ware_no char(10))
AS
BEGIN
    DECLARE @checkIn_num int, @checkOut_num int, @rate numeric(3,2)
    
    SELECT sum(checkInQuantity)
    FROM CheckInDetails
    WHERE wareNo=@ware_no

    SELECT sum(checkOutQuantity)
    FROM CheckOutDetails
    WHERE wareNo=@ware_no

    IF @checkIn_num > 0
	SELECT @rate=@checkOut_num/@checkIn_num
    ELSE
	BREAK
END
EXEC wareRate 'AB100001'
GO





