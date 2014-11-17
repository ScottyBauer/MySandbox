#!/bin/bash


while true; do
   curl "http://www.acs.utah.edu/uofu/stu/scheduling/crse-info?term=1154&subj=CS&catno=6810" | grep -C1 "<td bgcolor=#eeeeee align=center><font face=\"Arial\" size=\"-2\">" | awk -F"<td bgcolor=#eeeeee align=center><font face=\"Arial\" size=\"-2\">" '{print $1}' | grep "Computer Architecture" -A 6 | grep 68 > /dev/null

   if [ $? != 0 ]; then
       echo "class is open, notifying sarah and scott"
       echo "CLASS IS OPEN" | mail -s OPEN_CLASS sbauer@eng.utah.edu
       echo "CLASS IS OPEN" | mail -s OPEN_CLASS ###REDACTED##
       exit
   fi

echo "queried"
sleep 35s

done
