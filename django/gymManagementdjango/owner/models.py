from django.db import models

# Create your models here.
class TrainerDetails(models.Model):
    tid = models.AutoField(primary_key=True)
    tname = models.CharField(max_length=50)
    tdob = models.DateField()
    tgender = models.CharField(max_length=10)
    temail = models.EmailField(unique=True, null=False)
    tphone = models.CharField(max_length=10, unique=True, null=False)
    tusername = models.CharField(max_length=50)
    tpassword = models.CharField(max_length=20)
    timage = models.ImageField(upload_to='images')

    class Meta:
        db_table = 'trainerdetails'

class EmployeeDetails(models.Model):
    eid = models.AutoField(primary_key=True)
    ename = models.CharField(max_length=50)
    edob = models.DateField()
    egender = models.CharField(max_length=10)
    eemail = models.EmailField(unique=True, null=False)
    ephone = models.CharField(max_length=10, unique=True, null=False)
    eusername = models.CharField(max_length=20)
    epassword = models.CharField(max_length=50, unique=True, null=False)
    eimage = models.ImageField(upload_to='images')
    
    class Meta:
        db_table = 'employeedetails'

class MemberDetails(models.Model):
    mid = models.AutoField(primary_key=True)
    mname = models.CharField(max_length=50)
    mdob = models.DateField()
    mgender = models.CharField(max_length=10)
    memail = models.EmailField(unique=True, null=False)
    mphone = models.CharField(max_length=10, unique=True, null=False)
    musername = models.CharField(max_length=50)
    mpassword = models.CharField(max_length=50, unique=True, null=False)
    mtrainerid = models.CharField(max_length=20)
    mimage = models.ImageField(upload_to='images')

    class Meta:
        db_table = 'memberdetails'



