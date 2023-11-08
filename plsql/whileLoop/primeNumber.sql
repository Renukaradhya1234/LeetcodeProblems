declare
	out varchar(20) := 'prime number';
	num number;
	i number := 2;
begin
	num := &num;
	while i<num loop
		if mod(num, i) = 0 then
			out := 'not prime number';
			exit;
		end if;
		i := i+1;
	end loop;
	dbms_output.put_line(out);
end;
/
