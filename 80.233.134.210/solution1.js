function isPrime(value) {

  if(value > 2 && value % 2 == 0){
    return false;
  } 

  var top = Math.sqrt(value) + 1;

   for(var i = 3; i < top; i+=2) {
        if(value % i === 0) {
            return false;
        }
    }
    return value > 1;
}

function test(){

  var num1 = parseInt(document.getElementsByClassName("challenge")[0].innerHTML.trim().split(',')[0].substr(1));

  var num2 =  parseInt(document.getElementsByClassName("challenge")[0].innerHTML.trim().split(',')[2]);

  var i;
  var input = document.getElementsByName('solution')[0];
  var result = "";
  for(i = num1 + 1; i < num2 - 0; i++){
    if(isPrime(i)){
      result += i + ",";
    }
  }
    

  input.value = result.substr(0,result.length-1);
  document.getElementsByTagName('form')[0].submit()
}

test();
