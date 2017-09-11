import java.math.*;
import static java.lang.Math.pow;
class pds{

  public static void main(String[] args){
  
    Integer sum = new Integer(0);
    BigInteger num = new BigInteger("2").pow(1000);

    System.out.println("The number we are working with is " + num.toString());
    for(int i = 0; i < num.toString().length(); i++){
      sum += new Integer(Character.getNumericValue(num.toString().charAt(i)));
    }
    System.out.println("The sum of intergers of that number is " + sum.toString());


  }

}
