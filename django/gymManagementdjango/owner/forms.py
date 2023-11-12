from django import forms
from .models import *

class TrainerForm(forms.ModelForm):
    class Meta:
        model = TrainerDetails
        fields = '__all__'
        exclude = ['tid']

        widgets= {
            'tname': forms.TextInput(attrs={'type': 'text',
                                            'class': 'input',
                                            'placeholder': 'Enter the name'}),
            'tdob': forms.DateInput(attrs={'type': 'date',
                                           'class': 'input'}),
            'tgender': forms.RadioSelect(choices=[
                ('M', 'Male'),
                ('F', 'Female')
            ]),
            'temail': forms.TextInput(attrs={'type': 'email',
                                            'class': 'input',
                                            'placeholder': 'Enter the Email'}),
            'tphone': forms.TextInput(attrs={'type': 'text',
                                             'class': 'input',
                                             'placeholder': 'Enter the phone number'}),
            'tusername': forms.TextInput(attrs={'type': 'text',
                                                'class': 'input',
                                                'placeholder': 'Enter the username'}),

            'tpassword': forms.PasswordInput(attrs={'type': 'password',
                                                    'class': 'input',
                                                    'placeholder': 'Enter the password'}),
            'timage': forms.FileInput(attrs={'type': 'file',
                                             'class': 'input'})
        }

        labels = {
            'tname': '',
            'tdob': '',
            'tgender': 'Gender',
            'temail': '',
            'tphone': '',
            'tusername': '',
            'tpassword': '',
            'timage': '',
        }



class EmployeeForm(forms.ModelForm):
    class Meta:
        model = EmployeeDetails
        fields = '__all__'
        exclude = ['eid']

        widgets = {
            'ename': forms.TextInput(attrs={'type': 'text',
                                            'class': 'input',
                                            'placeholder': 'Enter the name'}),
            'edob': forms.DateInput(attrs={'type': 'date',
                                           'class': 'input'}),
            'egender': forms.RadioSelect(choices=[
                ('M', 'Male'),
                ('F', 'Female')
            ]),
            'eemail': forms.TextInput(attrs={'type': 'email',
                                            'class': 'input',
                                            'placeholder': 'Enter the email'}),
            'ephone': forms.TextInput(attrs={'type': 'text',
                                             'class': 'input',
                                             'placeholder': 'Enter the phone number'}),
            'eusername': forms.TextInput(attrs={'type': 'text',
                                                'class': 'input',
                                                'placeholder': 'Enter the username'}),
            'epassword': forms.TextInput(attrs={'type': 'password',
                                                'class': 'input',
                                                'placeholder': 'Enter the password'}),
            'eimage': forms.FileInput(attrs={'type': 'file',
                                             'class': 'input'})                                
            
        }

        labels = {
            'ename': "",
            'edob': '',
            'egender': 'Gender',
            'eemail': '',
            'ephone': '',
            'eusername': '',
            'epassword': "",
            'eimage': ''

        }

class MemberForm(forms.ModelForm):
    class Meta:
        model = MemberDetails

        fields = '__all__'
        exclude = ['mid']

        details = []
        obj = TrainerDetails.objects.all()
        for i in obj:
            print(f'this are trainer option: {i.tname}')
            details.append((i.tid, i.tname))

        widgets = {
            'mname': forms.TextInput(attrs={
                'type': 'text',
                'class': 'input',
                'placeholder': 'Enter the name'
            }),
            'mdob': forms.DateInput(attrs={'type': 'date',
                                           'class': 'input'}),
            'mgender': forms.RadioSelect(choices=[
                ('M', 'Male'),
                ('F', 'Female')
            ]),
            'memail':forms.TextInput(attrs={'type': 'email',
                                            'class': 'input',
                                            'placeholder': 'Enter the Email'}),
            'mphone': forms.TextInput(attrs={'type': 'text',
                                            'class': 'input',
                                            'placeholder': 'Enter the phone number'}),
            'musername': forms.TextInput(attrs={'type': 'text',
                                                'class': 'input',
                                                'placeholder': 'Enter the username'}),
            'mpassword': forms.TextInput(attrs={'type': 'password',
                                                'class': 'input',
                                                'placeholder': 'Enter the password'}),
            'mtrainerid': forms.Select(choices=details, attrs={'class': 'input',
                                                               'placeholder': 'Enter the trainer id'}),
            'mimage': forms.FileInput(attrs= {'class': 'input',
                                              'type': 'file'}) 
        }

        labels = {
            'mname': "",
            'mdob': '',
            'mgender': 'Gender',
            'memail': '',
            'mphone': '',
            'musername': '',
            'mpassword': "",
            'mtrainerid': '',
            'mimage': ''

        }

class TrainerUpdateForm(forms.ModelForm):
    class Meta:
        model = TrainerDetails
        fields = '__all__'
        exclude = ['tid', 'tpassword']

        widgets= {
            'tname': forms.TextInput(attrs={'type': 'text',
                                            'class': 'input',
                                            'placeholder': 'Enter the name'}),
            'tdob': forms.DateInput(attrs={'type': 'date',
                                           'class': 'input'}),
            'tgender': forms.RadioSelect(choices=[
                ('M', 'Male'),
                ('F', 'Female')
            ]),
            'temail': forms.TextInput(attrs={'type': 'email',
                                            'class': 'input',
                                            'placeholder': 'Enter the Email'}),
            'tphone': forms.TextInput(attrs={'type': 'text',
                                             'class': 'input',
                                             'placeholder': 'Enter the phone number'}),
            'tusername': forms.TextInput(attrs={'type': 'text',
                                                'class': 'input',
                                                'placeholder': 'Enter the username'}),

            'timage': forms.FileInput(attrs={'type': 'file',
                                             'class': 'input'})
        }

        labels = {
            'tname': '',
            'tdob': '',
            'tgender': 'Gender',
            'temail': '',
            'tphone': '',
            'tusername': '',
            'timage': '',
        }

class EmployeeUpdateForm(forms.ModelForm):
    class Meta:
        model = EmployeeDetails
        fields = '__all__'
        exclude = ['eid', 'epassword']

        widgets = {
            'ename': forms.TextInput(attrs={'type': 'text',
                                            'class': 'input',
                                            'placeholder': 'Enter the name'}),

            'edob': forms.DateInput(attrs={'type': 'date',
                                           'class': 'input'}),

            'egender': forms.RadioSelect(choices=[
                ('M', 'Male'),
                ('F', 'Female')
            ]),

            'eemail': forms.TextInput(attrs={'type': 'email',
                                            'class': 'input',
                                            'placeholder': 'Enter the email'}),

            'ephone': forms.TextInput(attrs={'type': 'text',
                                             'class': 'input',
                                             'placeholder': 'Enter the phone number'}),

            'eusername': forms.TextInput(attrs={'type': 'text',
                                                'class': 'input',
                                                'placeholder': 'Enter the username'}),

            'eimage': forms.FileInput(attrs={'type': 'file',
                                             'class': 'input'})                                
            
        }

        labels = {
            'ename': "",
            'edob': '',
            'egender': 'Gender',
            'eemail': '',
            'ephone': '',
            'eusername': '',
            'eimage': ''

        }



class MemberUpdateForm(forms.ModelForm):
    class Meta:
        model = MemberDetails

        fields = '__all__'
        exclude = ['mid', 'mpassword']

        details = []
        obj = TrainerDetails.objects.all()
        for i in obj:
            print(f'this are trainer option: {i.tname}')
            details.append((i.tid, i.tname))

        widgets = {
            'mname': forms.TextInput(attrs={
                'type': 'text',
                'class': 'input',
                'placeholder': 'Enter the name'
            }),
            'mdob': forms.DateInput(attrs={'type': 'date',
                                           'class': 'input'}),
            'mgender': forms.RadioSelect(choices=[
                ('M', 'Male'),
                ('F', 'Female')
            ]),
            'memail':forms.TextInput(attrs={'type': 'email',
                                            'class': 'input',
                                            'placeholder': 'Enter the Email'}),
            'mphone': forms.TextInput(attrs={'type': 'text',
                                            'class': 'input',
                                            'placeholder': 'Enter the phone number'}),
            'musername': forms.TextInput(attrs={'type': 'text',
                                                'class': 'input',
                                                'placeholder': 'Enter the username'}),
            'mtrainerid': forms.Select(choices=details, attrs={'class': 'input',
                                                               'placeholder': 'Enter the trainer id'}),
            'mimage': forms.FileInput(attrs= {'class': 'input',
                                              'type': 'file'}) 
        }

        labels = {
            'mname': "",
            'mdob': '',
            'mgender': 'Gender',
            'memail': '',
            'mphone': '',
            'musername': '',
            'mtrainerid': '',
            'mimage': ''

        }

