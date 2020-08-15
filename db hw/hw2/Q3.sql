/*EXECUTED ON: w3schools.com https://www.w3schools.com/sql/trysql.asp?filename=trysql_op_in 
NOTE:RUN ALL COMMANDS INDIVIDUALLY.
 */

create table proj (PID char(4) not null, Step number not null, Status char(1) not null,PRIMARY KEY (PID,Step));

insert into proj values('P100',0,'C'),('P100',1,'W'),('P100',2,'W'),('P201',0,'C'),('P201',1,'C'),('P333',0,'W'),('P333',1,'W'),
('P333',2,'W'),('P333',3,'W');

select PID from (select PID,count(*) from proj where Status='C' group by PID having count(*)=1);
/*
Result:
Number of Records: 1
PID
P100


EXPLANATION:


select PID from proj where Status='C'; 

Result:
Number of Records: 3
PID
P100
P201
P201

Selects all PID where there is a 'C' step. Duplicate PIDs are returned as a PID can have >1 'C' completeed steps.


select PID,count(*) from proj where Status='C' group by PID ;

 Result:
Number of Records: 2
PID	count(*)
P100	1
P201	2

Displays PID from proj table where only 'C' completed steps are there and also counts number of 'C' steps

select PID,count(*) from proj where Status='C' group by PID having count(*)=1;

Result:
Number of Records: 1
PID	count(*)
P100	1

Selects only PID where number of completed steps 'C' is 1. By the formulation of the question, A step can be completed only if all previous steps are completed. If only 1 step is completed, then it means that it must be step 0 and nothing else.
*/