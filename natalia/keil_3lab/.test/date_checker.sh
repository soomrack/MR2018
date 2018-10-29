#!/bin/sh

# format is YYYY-MM-DD
# unfortunately, alpine is rather weak in dates
# you also need to add tzdata package for european timezones
TZ='Europe/Moscow'
export TZ
current_time="$(date +%s)"
due_time="$(date --date='2018-10-28 01:00' +%s)"

echo "Due time is:"
date -d @$((due_time))

echo

echo "Current time is:"
date -d @$((current_time))

time_left=$(($due_time-$current_time))

time_left_in_days=$((time_left/86400))
time_left_in_hours=$((time_left/3600))

time_in_days_max=42 # six weeks

if [ $time_left_in_days -lt -${time_in_days_max} ]; then
    echo -e "\e[41mYou are $((-1*time_left_in_days)) days ($((-1*time_left_in_hours)) hours) late. TOO LATE.\e[0m"
    exit 1
elif [ $time_left -lt 0 ]; then
    echo -e "\e[30;48;5;208mYou are $((-1*time_left_in_days)) days ($((-1*time_left_in_hours)) hours) late. Not too late though.\e[0m"
else
    echo -e "\e[30;42m${time_left_in_days} days ( ${time_left_in_hours} hours) left, still plenty of time!\e[0m"
fi

