from django import forms
from .models import *

class RegistrationForm(forms.ModelForm):
    class Meta:
        model = RegistrationTable
        fields = '__all__'
        exclude = ['customerId']

        widgets= {
            "name" : forms.TextInput(attrs={'type': 'text',
                                            'class': 'input',
                                            'placeholder': 'Enter the name'}),
            
            "phoneNumber" : forms.TextInput(attrs={'type': 'text',
                                            'class': 'input',
                                            'placeholder': 'Enter the phone number'}),

            "email" : forms.TextInput(attrs={'type': 'email',
                                            'class': 'input',
                                            'placeholder': 'Enter the email'}),

            "username" : forms.TextInput(attrs={'type': 'text',
                                            'class': 'input',
                                            'placeholder': 'Enter the username'}),

            "password" : forms.TextInput(attrs={'type': 'password',
                                            'class': 'input',
                                            'placeholder': 'Enter the password'}),
        }


        labels = {
            "name" : "",
            "phoneNumber" : "",
            "email" : "",
            "username" : "",
            "password" : ""
        }

ratingChoice = [(1,1), (2,2), (3,3), (4,4), (5,5)]
class EnquiryForm(forms.ModelForm):
    class Meta:
        model = EnquiryTable
        exclude = ["enquiryId"]
        fields = "__all__"

        widgets= { 
            "rating" : forms.Select(choices=ratingChoice, attrs={
                "class" : "input"
            }),

            "enquiryStatement" : forms.Textarea(attrs={'class': 'input',
                                            'placeholder': 'Type Here'}),   

            "customerId" : forms.TextInput(attrs={'type': 'hidden',
                                            'class': 'input'}),         
        }