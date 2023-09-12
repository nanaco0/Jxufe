package exercise07;

import java.util.GregorianCalendar;

public class MyDate {
	private int year, month, day;
	
	public MyDate() {
		GregorianCalendar date = new GregorianCalendar();
		this.year=date.get(GregorianCalendar.YEAR);
		this.month=date.get(GregorianCalendar.MONTH);
		this.day=date.get(GregorianCalendar.DAY_OF_MONTH);
	}
	
	public MyDate(long l){
        GregorianCalendar date = new GregorianCalendar();
        date.setTimeInMillis(l);
        year = date.get(GregorianCalendar.YEAR);
        month = date.get(GregorianCalendar.MONTH);
        day = date.get(GregorianCalendar.DAY_OF_MONTH);
    }

    public MyDate(int year, int month, int day){
        this.year = year;
        this.month = month;
        this.day = day;
    }

    public void setDate(long elapsedTime){
        GregorianCalendar gc = new GregorianCalendar();
        gc.setTimeInMillis(elapsedTime + toCalender(year, month, day));
        year = gc.get(GregorianCalendar.YEAR);
        month = gc.get(GregorianCalendar.MONTH);
        day = gc.get(GregorianCalendar.DAY_OF_MONTH);
    }
    public long toCalender(int year, int month, int day){
        day += year * 365;
        switch (month){
            case 11: day += 31;
            case 10: day += 30;
            case 9: day += 31;
            case 8: day += 30;
            case 7: day += 31;
            case 6: day += 31;
            case 5: day += 30;
            case 4: day += 31;
            case 3: day += 30;
            case 2: day += 31;
            case 1: day += 28;
        }
        return (long) day * 24 * 60 * 60 * 1000;
    }
}
