from django.db import models
from django.contrib.auth.hashers import make_password, check_password

# Create your models here.
class RegistrationTable(models.Model):
    customerId = models.AutoField(primary_key=True)
    name = models.CharField(max_length=100)
    phoneNumber = models.CharField(max_length=10)
    email = models.EmailField()
    username = models.CharField(max_length=100, unique=True)
    password = models.CharField(max_length=150)

    def save(self, *args, **kwargs):
        # Hash the password before saving to the database
        self.password = make_password(self.password)
        super().save(*args, **kwargs)

    def authenticate(self, password , username):
        if self.username == username:
            if check_password(password, self.password):
                return True
            return False
        return False
    
class EnquiryTable(models.Model):
    enquiryId = models.AutoField(primary_key=True)
    rating = models.CharField(max_length=10)
    enquiryStatement = models.CharField(max_length=1000)
    customerId = models.ForeignKey(to="RegistrationTable", to_field="customerId", on_delete=models.CASCADE)