declare
	emp_id number;
	cursor emp_empno is
		select empno
		from emp;
Begin
	dbms_output.put_line('empno');
	for emp_id in emp_empno
		loop
			dbms_output.put_line(emp_id.empno);
		end loop;
end;
/
