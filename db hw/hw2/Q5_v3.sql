/*
EXECUTED ON: w3schools.com https://www.w3schools.com/sql/trysql.asp?filename=trysql_op_in
NOTE:RUN ALL COMMANDS INDIVIDUALLY.
*/
/*
SOLUTION 3: Using and 
*/
select Distinct(Instructor) from job where Instructor in (select Instructor from job where Subject='Javascript') and Instructor in (select Instructor from job where Subject='Scratch') and Instructor in (select Instructor from job where Subject='Python');
/*
Number of Records: 2
Instructor
Dat
Emscr


EXPLANATION:
Here find the list of all instructors who teach each of the 3 courses(i. find all instructors who can teach Javascript, find all instructors who can teach Python and find all instrutors who can teach Scratch) and then check for each row if that Instructor is present in each of the list.

(select Instructor from job where Subject='Javascript') finds list of instructors who teach Javascript
(select Instructor from job where Subject='Scratch') finds list of instructors who teach Scratch
(select Instructor from job where Subject='Python') finds list of instructors who teach Python

Instructor in (select Instructor from job where Subject='Javascript') checks for a particular row if the instructor is present in the subquery table of Javascript instructors.
Instructor in (select Instructor from job where Subject='Scratch') checks for a particular row if the instructor is present in the subquery table of Scratch instructors.

the 1st 'and' keyword checks for a particular row if the instructor is present in the subquery table of Scratch instructors and Javascript instructors.

Instructor in (select Instructor from job where Subject='Python') checks for a particular row the instructor is present in the subquery table of Pythoninstructors.

the 2st 'and' keyword checks for a particular row if the instructor is present in the subquery table of Scratch,Javascript instructors and Python instructors.

*/