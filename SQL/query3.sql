SELECT e.*, r.*
FROM employees e  
      inner join departments d
          on e.department_id = d.department_id
      inner join locations l
          on d.location_id = l.location_id
      inner join countries c
          on l.country_id = c.country_id
      inner join regions r
          on c.region_id = r.region_id
WHERE e.salary * 12 > 300000;
