import java.math.*;
import java.util.ArrayList;

class fds{

  public static ArrayList<BigInteger> fs = new ArrayList<BigInteger>();

  public static BigInteger dynFactorial(int num){
    if(num == 0){
      return new BigInteger("1");
    }

    //System.out.println("Working on number " + num + " current state is " + fs.get(num - 1));
    
    if(fs.get(num - 1).intValue() == 0){
      fs.set(num - 1,dynFactorial(num - 1).multiply(new BigInteger(String.valueOf(num))));
    //  System.out.println("Working on number " + num + " changed state is " + fs.get(num - 1));
    }
  
    return fs.get(num-1);
  }

  public static void main(String[] args){
  
    if(args.length != 1){
      System.err.println("Usage: java fds <Number>");
      return;
    }
    int num = Integer.parseInt(args[0]);  
    for(int i = 0; i < num; i++){
      fs.add(new BigInteger("0"));
    }
    System.out.println("The length of the list is " + fs.size()); 
    BigInteger dyNum = dynFactorial(num);
    System.out.println("The factorial for number " + num + " is " + dyNum);
 
    int sum = 0;
    for(int i = 0; i < dyNum.toString().length(); i++){
      sum += new Integer(Character.getNumericValue(dyNum.toString().charAt(i)));
    }

    System.out.println("The sum of digits of " + dyNum + " is " + sum);
  }
}
