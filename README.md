# Workout Schedule
This is a console app that helps you to memory and sort the workout exercises. Exercises that exceeds 7 days for the last time doing it will be reset to "0 days ago", which will be sorted to the top of the schedule. Sorting algorithm uses bubble sort which retains the stableness, aka the first "0 days ago" will remain the first place until you pick that exercise manuelly.
# Caution
* The amount of the rows that displaying is hard-coded to 5 rows.
* Thus to be able to see the remaining unseen exercises, you need to first pick the showing exercises as today's training plan, so other exercises sorts up.
* The schedule updates and sorts once each day according to the parameter "last day".
* So please aim for picking different exercises each day/week.
# How to use (windows only)
* run the .exe to generate empty schedule.txt
* add the name of the execises into the schedule, one line per schedule
* run the .exe and input the index number of the execises that displaied on the console followed by enter.
* the date will be saved when closing the console automatically.
<img width="645" height="475" alt="image" src="https://github.com/user-attachments/assets/b9bd0269-e81a-469e-aa1a-365f35898267" />
