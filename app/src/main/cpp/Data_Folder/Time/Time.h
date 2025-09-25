#pragma once
#include "pstring.h"
    typedef long time_type;
    
    enum TimeUnit
    {
        DAYS, WEEKS, MONTHS, YEARS, HOURS, MINUTES, SECONDS, MILLISECONDS, MICROSECONDS
    };
    
    struct S_PRA_API Time
    {
        time_type m_time;
        
        Time();
        Time(const Time &value);
        explicit Time(const std::string &value);
        Time(const time_t &time);
        Time(const tm *time);
        
        void Set(const std::string &value);
        void Set(const time_t &time);
        void Set (const tm *time);
        
        // difference
        static int GetDiffDays(const Time &time1, const Time &time2);
        static int GetDiffMonths(const Time &time1, const Time &time2);
        static int GetDiffYears(const Time &time1, const Time &time2);
        static int GetDiffHours(const Time &time1, const Time &time2);
        static int GetDiffMinutes(const Time &time1, const Time &time2);
        static int GetDiffSeconds(const Time &time1, const Time &time2);
        
        std::string CountDownTimer(const Time *end, ImColor* col, bool prefix = false, bool bInfoTime = true);
        
        friend bool operator == (const Time &time1, const Time &time2);
        friend bool operator < (const Time &time1, const Time &time2);
        friend bool operator != (const Time &time1, const Time &time2);
        friend bool operator <= (const Time &time1, const Time &time2);
        friend bool operator > (const Time &time1, const Time &time2);
        friend bool operator >= (const Time &time1, const Time &time2);
        
    };
    
    struct S_PRA_API SecondTime
    {
        int year; // years since 1900
        int month; // 0-11
        int day; // 1-31
        int hour; // 0-23
        int minute; // 0-59
        int second; // 0-61*
        int millisecond;
        bool valid;
        
        SecondTime();
        SecondTime(long long time);
        SecondTime(const tm *time);
        SecondTime(const std::string &value);
        
        void setYearsDay(const int *monthTable, const int *lengths, int yearDay);
        
       /*
        * Get amount of milliseconds from J1n, 1 of the 1'th year
        */
        long long getTime();
        
       /*
        * Returns day-of-year for the date
        */
        int dayOfYear() const;
       /*
        * Add months to the date-time
        */
        void incMonth(int months) { month += months; }

       /*
        * Add years to the date-time
        */
        void incYear(int years) { year += years; }

       /*
        * Get date formatted as yyyy-MM-dd
        */
        std::string formatDate(void) const;

       /*
        * Get date and time formatted as yyyy-MM-dd hh:mm:ss
        */
        std::string formatDateTime(void) const;

       /*
        * Get amount of months since a previous date
        * (this date-time MUST be before or equal to the "from" one)
        */
        int monthsAfter(const SecondTime &from);
 
       /*
        * Check the time before the event time
        */
        bool checkFutureDate(SecondTime* _time);

       /*
        * Get SecondTime in representation of struct tm
        */
        void aSecondTime(tm *time);
  
       /*
        * Get Owner Millisecond
        */
        long getMillis() { return (long)millisecond; }
    };
    
    S_PRA_EXTERN Time *time_instance;
    
    pstring ToTimeUnit(const TimeUnit&, long, bool);
    
    inline bool operator ==(const Time & time1, const Time & time2)
    {
        return time1.m_time == time2.m_time;
    }

    inline bool operator <(const Time & time1, const Time & time2)
    {
        return time1.m_time < time2.m_time;
    }

    inline bool operator !=(const Time & time1, const Time & time2)
    {
        return !(time1 == time2);
    }

    inline bool operator <=(const Time & time1, const Time & time2)
    {
        return time1 < time2 || time1 == time2;
    }

    inline bool operator >(const Time & time1, const Time & time2)
    {
        return !(time1 <= time2);
    }

    inline bool operator >=(const Time & time1, const Time & time2)
    {
        return !(time1 < time2);
    }
    
    inline const char* ToMicros(long duration, bool prefix = false) {
        return ToTimeUnit(MICROSECONDS, duration, prefix).c_str();
    }
    
    inline const char* ToMillis(long duration, bool prefix = false) {
        return ToTimeUnit(MILLISECONDS, duration, prefix).c_str();
    }
    
    inline const char* ToSeconds(long duration, bool prefix = false) {
        return ToTimeUnit(SECONDS, duration, prefix).c_str();
    }
    
    inline const char* ToMinutes(long duration, bool prefix = false) {
        return ToTimeUnit(MINUTES, duration, prefix).c_str();
    }
    
    inline const char* ToHours(long duration, bool prefix = false) {
        return ToTimeUnit(HOURS, duration, prefix).c_str();
    }
    
    inline const char* ToDays(long duration, bool prefix = false) {
        return ToTimeUnit(DAYS, duration, prefix).c_str();
    }
    
    inline const char* ToWeeks(long duration, bool prefix = false) {
        return ToTimeUnit(WEEKS, duration, prefix).c_str();
    }
    
    inline const char* ToMonths(long duration, bool prefix = false) {
        return ToTimeUnit(MONTHS, duration, prefix).c_str();
    }
    
    inline const char* ToYears(long duration, bool prefix = false) {
        return ToTimeUnit(YEARS, duration, prefix).c_str();
    }

