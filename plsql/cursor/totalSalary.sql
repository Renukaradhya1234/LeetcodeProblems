Declare
	cursor emp_salary is
		select sal
		from emp;
	total_salary number := 0;
Begin
	for i in emp_salary
		loop
			total_salary := total_salary + i.sal;
		end loop;
	dbms_output.put_line('total salary of employees are: '||total_salary);
End;
/
