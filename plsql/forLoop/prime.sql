declare
	num number ;
	result varchar(20) := 'prime number';
begin
	num := &number;
	for var in 2..num-1
		loop
			if mod(num, var) = 0 then 
				result := 'not prime number';
				exit;
			end if;
		end loop;
	dbms_output.put_line(result);
end;
/
