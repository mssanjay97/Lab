/*
SOLUTION 1): 
EXECUTED ON: w3schools.com  https://www.w3schools.com/sql/trysql.asp?filename=trysql_op_in 

Redesign the table such that intead of having start time and end time, we can have slots of time such that each slot is 1 hour. Slot 0 is from 00::00 hours to 01:00 hrs, Slot 1 is from 01:00 hrs to 02:00 hrs .... slot 10 is from 10:00 hrs to 11:00 hrs, slot 20 is form 20:00 hrs to 21:00 hrs and so on(24 hrs military style format).So slot i is from i:00 hrs to i+1:00 hrs . Primary key is room number and slot number both.  For a project group to book a room for a specific period of time, it should be entered for all slots.Ex: is a group 'db' wants to book room 1 from 8 am to 12 am, then the values (1,8,'db') ,(1,9'db'),(1,10,'db'),(1,11,'db') . This method solves both the problems as there is no end time since all slots are assumed to be 1 hour so there is no way to wrongly enter an end time earlier than start time/ enter a start time before the end time of pre-existing event. 
*/
CREATE TABLE ProjectRoomBookings
(roomNum INTEGER NOT NULL,
slot INTEGER NOT NULL ,
groupName CHAR(10) NOT NULL,
PRIMARY KEY (roomNum, slot),
CONSTRAINT slotchk CHECK (slot between 0 and 23));
/*
Note: checking slot is between 0 and 23 prevents any invalid slot entry.


SOLUTION 2): create trigger on the same table as mentioned in the question to check both problems do not occur by raising an exception.
ORACLE SQL:
EXECUTED ON: https://livesql.oracle.com/apex/f?p=590:1000
NOTE:while executing it in oracle sql, execute each statement individually, not everything at once.
*/
CREATE TABLE ProjectRoomBookings
(roomNum INTEGER NOT NULL,
startTime INTEGER NOT NULL,
endTime INTEGER NOT NULL,
groupName CHAR(10) NOT NULL,
PRIMARY KEY (roomNum, startTime)); 


/*TRIGGER TO CHECK START DATE IS EARLIER THAN END DATE*/
create or replace trigger datechk  before insert on ProjectRoomBookings  for each row 
declare
date_error exception;
begin  
if (:new.startTime>:new.endTime) then 
dbms_output.put_line('start time should be early');
raise date_error;
else
NULL;
end if;  
end;

/*TRIGGER TO CHECK IS START TIME OF A NEW PROJECT BOOKING DOES NOT CLASH WITH ANOTHER ON GOING PROJECT*/
create or replace trigger groupchk  before insert on ProjectRoomBookings  for each row 
declare
group_error exception;
cnt INTEGER;
begin  
select count(*) into cnt from ProjectRoomBookings p where p.roomNum=:new.roomNum and :new.startTime < p.endTime ;
if  cnt>0  then 
dbms_output.put_line('start time is clashing');
raise group_error;
else
NULL;
end if;  
end;
