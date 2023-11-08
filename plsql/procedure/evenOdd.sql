create or replace procedure even_odd_function( num in number, result out varchar)
as
Begin
	if mod(num, 2) = 0 then
		result := 'even number';
	else
		result := 'odd number';
	end if;
End;
/


Declare 
	res varchar(20);
Begin
	even_odd_function(6, res);
	dbms_output.put_line(res);
End;
/
