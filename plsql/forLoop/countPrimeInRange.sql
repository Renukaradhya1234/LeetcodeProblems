Declare
	num_start number;
	num_end number;
	total_prime number := 0;
	total_non_prime number := 0;
	check_prime varchar(20) := 'prime';
	total_number number := 0;
Begin
	num_start := &starting_number;
	num_end := &ending_number;
	
	if num_end < num_start then
		dbms_output.put_line('ending number should be greater than starting number');
	else
		for num in num_start..num_end
			loop
				for i in 2..num-1
					loop
						if mod(num, i) = 0 then
							check_prime := 'not prime';
							exit;
						end if;
					end loop;
				if check_prime = 'prime' then
					dbms_output.put_line(num);
					total_prime := total_prime + 1;
				else
					total_non_prime := total_non_prime + 1;
					check_prime := 'prime';
				end if;
			end loop;
		dbms_output.put_line('total prime numbers are: '||total_prime);
		dbms_output.put_line('total non prime numbers are: ' || total_non_prime);
		total_number := total_prime + total_non_prime;
		dbms_output.put_line('total numbers counted are: ' || total_number);
	end if;
end;
/
