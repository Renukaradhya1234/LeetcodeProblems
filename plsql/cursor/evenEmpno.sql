Declare
	empid number;
	cursor eid is
		select empno
		from emp;
Begin
	open eid;
	loop
		Exit when eid%notfound;
		fetch eid into empid;
		if mod(empid, 2) = 0 then
			dbms_output.put_line(empid);
		end if;
	end loop;
	close eid;
End;
/
