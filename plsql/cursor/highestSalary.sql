Declare
	cursor emp_salary is
		select sal
		from emp;
	highest_salary number := 0;
Begin
	for salary in emp_salary
		loop
			if salary.sal > highest_salary then
				highest_salary := salary.sal;
			end if;
		end loop;
	dbms_output.put_line('the highest salary is : '|| highest_salary);
end;
/
