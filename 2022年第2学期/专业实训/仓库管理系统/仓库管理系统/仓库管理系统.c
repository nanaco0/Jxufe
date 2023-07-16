#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include "颜色主题.h"
#include "结构体.h"
#include "文件读取.h"
#include "文件保存.h"
#include "显示库存.h"
#include "货物调拨.h"
#include "查找货物.h"
#include "进货.h"
#include "退货.h"

#include "销售记录.h"
#include "操作者管理.h"
#include "供应商管理.h"
#include "系统管理界面.h"
#include "普通操作界面.h"
#include "管理员注册.h"
#include "管理员登录.h"
#include "操作员注册.h"
#include "操作员登录.h"
#include "主菜单.h"
void testData()
{ // 导入测试数据

    struct admin adminTest[6] = {
        {"ad2291100", "root", "abc123..", "18618660000"},
        {"ad2291101", "c", "abc123..", "18618660001"},
        {"ad2291102", "l", "abc123..", "18618660002"},
        {"ad2291103", "f", "abc123..", "18618660003"},
        {"ad2291104", "cyn", "abc123..", "18618660004"},
        {"ad2291105", "ly", "abc123..", "18618660005"},
    };

    FILE* file = fopen("系统管理员.txt", "w"); // 打开文件

    if (file == NULL)
    {
        printf("无法打开文件。\n");
        exit(0);
    }

    int numAdminTest = sizeof(adminTest) / sizeof(struct admin);

    for (int i = 0; i < numAdminTest; i++)
    {
        fwrite(&adminTest[i], sizeof(struct admin), 1, file);
    }

    fclose(file); // 关闭文件

    printf("成功将系统管理员写入txt文件。\n");

    struct user userTest[10] = {
        {"u002291101", "马德胜", "abc123..", "17618660001"},
        {"u002291102", "李勤", "abc123..", "17618660002"},
        {"u002291103", "龚彪", "abc123..", "17618660003"},
        {"u002291104", "林木华", "abc123..", "17618660004"},
        {"u002291105", "沈墨", "abc123..", "17618660005"},
        {"u002291106", "傅卫军", "abc123..", "17618660006"},
        {"u002291107", "隋东", "abc123..", "17618660007"},
        {"u002291108", "王响", "abc123..", "17618660008"},
        {"u002291109", "王阳", "abc123..", "17618660009"},
        {"u002291110", "王北", "abc123..", "17618660010"} };

    file = fopen("普通操作员.txt", "w"); // 打开文件

    if (file == NULL)
    {
        printf("无法打开文件。\n");
        exit(0);
    }

    int numUserTest = sizeof(userTest) / sizeof(struct user);

    for (int i = 0; i < numUserTest; i++)
    {
        fwrite(&userTest[i], sizeof(struct user), 1, file);
    }

    fclose(file); // 关闭文件

    printf("成功将普通操作员写入txt文件。\n");

    struct cargo cargoTest[12] = {
        {"2023070601", "文件夹", 100, "个", "s002291101"},
        {"2023070602", "票据夹", 200, "个", "s002291102"},
        {"2023070603", "档案袋", 150, "个", "s002291103"},
        {"2023070604", "名片盒", 100, "个", "s002291104"},
        {"2023070605", "公事包", 200, "个", "s002291105"},
        {"2023070606", "拉链袋", 150, "个", "s002291106"},
        {"2023070607", "文件柜", 100, "个", "s002291107"},
        {"2023070608", "资料架", 200, "个", "s002291108"},
        {"2023070609", "图纸夹", 150, "个", "s002291109"},
        {"2023070610", "订书机", 100, "个", "s002291110"},
        {"2023070612", "起钉器", 200, "个", "s002291101"},
        {"2023070613", "打孔器", 150, "个", "s002291102"} };

    file = fopen("货物.txt", "w"); // 打开文件

    if (file == NULL)
    {
        printf("无法打开文件。\n");
        exit(0);
    }

    int numCargoTest = sizeof(cargoTest) / sizeof(struct cargo);

    for (int i = 0; i < numCargoTest; i++)
    {
        fwrite(&cargoTest[i], sizeof(struct cargo), 1, file);
    }

    fclose(file); // 关闭文件

    printf("成功将货物写入txt文件。\n");

    struct cargoSold cargoSoldTest[12] = {
        {"2023070601", "文件夹", 50, "个", "北京", "u002291101"},
        {"2023070602", "票据夹", 50, "个", "北京", "u002291102"},
        {"2023070603", "档案袋", 50, "个", "北京", "u002291103"},
        {"2023070604", "名片盒", 80, "个", "南京", "u002291104"},
        {"2023070605", "公事包", 80, "个", "南京", "u002291105"},
        {"2023070606", "拉链袋", 80, "个", "南京", "u002291106"},
        {"2023070607", "文件柜", 60, "个", "天津", "u002291107"},
        {"2023070608", "资料架", 60, "个", "天津", "u002291108"},
        {"2023070609", "图纸夹", 60, "个", "天津", "u002291109"},
        {"2023070610", "订书机", 20, "个", "哈尔滨", "u002291110"},
        {"2023070612", "起钉器", 20, "个", "哈尔滨", "u002291101"},
        {"2023070613", "打孔器", 20, "个", "哈尔滨", "u002291102"} };

    file = fopen("销售记录.txt", "w"); // 打开文件

    if (file == NULL)
    {
        printf("无法打开文件。\n");
        exit(0);
    }

    int numCargoSoldTest = sizeof(cargoSoldTest) / sizeof(struct cargoSold);

    for (int i = 0; i < numCargoSoldTest; i++)
    {
        fwrite(&cargoSoldTest[i], sizeof(struct cargoSold), 1, file);
    }

    fclose(file); // 关闭文件

    printf("成功将销售记录写入txt文件。\n");

    struct supplier supplierTest[10] = {
        {"s002291101", "江西铜业集团有限公司", "15618660001", "江西省南昌市西湖区站前西路289号三星大厦"},
        {"s002291102", "江铃汽车集团有限公司", "15618660002", "江西省南昌市解放西路226号"},
        {"s002291103", "正邦集团有限公司", "15618660003", "江西省南昌市青山湖区洪都中大道18号"},
        {"s002291104", "江西方大钢铁集团有限公司", "15618660004", "江西省南昌市青山湖区洪都中大道孙家亭路4号"},
        {"s002291105", "双胞胎（集团）股份有限公司", "15618660005", "江西省南昌市北京西路194号"},
        {"s002291106", "新余钢铁集团有限公司", "15618660006", "江西省南昌市省府北二路68号"},
        {"s002291107", "晶科能源有限公司", "15618660007", "江西省南昌市右营街19号"},
        {"s002291108", "江西省建工集团有限责任公司", "15618660008", "江西省南昌市东湖区沿江北大道39号"},
        {"s002291109", "江西博能实业集团有限公司", "15618660009", "江西省南昌市东湖区阳明路207号"},
        {"s002291110", "江西济民可信集团有限公司", "15618660010", "江西省南昌市五纬路382号"} };

    file = fopen("供应商.txt", "w"); // 打开文件

    if (file == NULL)
    {
        printf("无法打开文件。\n");
        exit(0);
    }

    int numSupplierTest = sizeof(supplierTest) / sizeof(struct supplier);

    for (int i = 0; i < numSupplierTest; i++)
    {
        fwrite(&supplierTest[i], sizeof(struct supplier), 1, file);
    }

    fclose(file); // 关闭文件

    printf("成功将供应商写入txt文件。\n");
}

int main()
{
    printf("\n\n");
    printf("\t\t\t|------------------------------------------------------|\n");
    printf("\t\t\t|                                                      |\n");
    printf("\t\t\t|                                                      |\n");
    printf("\t\t\t|           ");
    printf("欢");
    Sleep(120);
    printf(" 迎");
    Sleep(120);
    printf(" 使");
    Sleep(120);
    printf(" 用");
    Sleep(120);
    printf(" 仓");
    Sleep(120);
    printf(" 库");
    Sleep(120);
    printf(" 管");
    Sleep(120);
    printf(" 理");
    Sleep(120);
    printf(" 系");
    Sleep(120);
    printf(" 统！");
    Sleep(120);
    printf("            |\n");
    printf("\t\t\t|                                                      |\n");
    printf("\t\t\t|                                                      |\n");
    printf("\t\t\t|------------------------------------------------------|\n");

    printf("\n\n\n\n\n\n\t\t\t\t\t");
    system("pause");

    // 导入测试数据
    testData();
    fileread();
    menu();
    return 0;
}