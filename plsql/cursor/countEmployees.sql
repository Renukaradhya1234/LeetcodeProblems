Declare
	cursor emp_details is
		select empno
		from emp;
	num number := 0;
Begin
	for i in emp_details
		loop
			num := num + 1;
		end loop;
	dbms_output.put_line('total no of employees are: '||num);
End;
/
