package exercise06;

public class Time{
    private long second;
    private long minute;
    private long hour;

    public Time(){
        long t = System.currentTimeMillis()/1000;
        second = t % 60;
        t /= 60;
        minute = t % 60;
        t /= 60;
        hour = t % 24;
    }

    public Time(long t){
        t /= 1000;
        second = t % 60;
        t /= 60;
        minute = t % 60;
        t /= 60;
        hour = t;
    }

    public Time(long hour, long minute, long second){
        this.hour = hour;
        this.minute = minute;
        this.second = second;
    }

    public long getSecond(){
        return second;
    }

    public long getMinute(){
        return minute;
    }

    public long getHour(){
        return hour;
    }

    public void setTime(long elapseTime){
        elapseTime /= 1000;
        this.second = elapseTime%60;
        elapseTime /= 60;
        this.minute = elapseTime%60;
        elapseTime /= 60;
        this.hour = elapseTime;
    }
}

