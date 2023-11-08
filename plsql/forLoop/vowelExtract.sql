declare
	string varchar(20);
	result varchar(20);
begin
	string := &string;
	for var in 1..length(string)
		loop
			if substr(string, var, 1) in ('a', 'e', 'i', 'o', 'u') then
				result := result|| substr(string, var, 1);
			end if;
		end loop;
	dbms_output.put_line(result);
end;
/
