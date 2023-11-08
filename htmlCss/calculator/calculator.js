let number = ''
one=()=>{
    document.getElementById('display').value+='1'
}

two=()=>{
    document.getElementById('display').value+='2'
}

three=()=>{
    document.getElementById('display').value+='3'
}

four=()=>{
    document.getElementById('display').value+='4'
}
five=()=>{
    document.getElementById('display').value+='5'
}

six=()=>{
    document.getElementById('display').value+='6'
}

seven=()=>{
    document.getElementById('display').value+='7'
}

eight=()=>{
    document.getElementById('display').value+='8'
}

nine=()=>{
    document.getElementById('display').value+='9'
}

zero=()=>{
    document.getElementById('display').value+='0'
}

dzero=()=>{
    document.getElementById('display').value+='00'
}

per=()=>{
    document.getElementById('display').value+='%'
}

div=()=>{
    document.getElementById('display').value+='/'
}

mul=()=>{
    document.getElementById('display').value+='*'
}

sub=()=>{
    document.getElementById('display').value+='-'
}

add=()=>{
    document.getElementById('display').value+='+'
}

dot=()=>{
    document.getElementById('display').value+='.'
}

allclear=()=>{
    document.getElementById('display').value=''
}
del=()=>{
    const a = document.getElementById('display').value;
    document.getElementById('display').value=a.slice(0, -1)
}

equal=()=>{
    let res=eval(document.getElementById('display').value)
    document.getElementById('display').value=res
}


document.addEventListener('keypress', (event)=>{
    let name=event.key
    if (name != 'Enter'){
        document.getElementById('display').value+=name   
    }
    else{
        equal()
    }
})