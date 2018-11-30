

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing	   
	   
   }
   
   //Partition for Port #'s - less than 0, 0 - 65535, < 65535
   public void testPortsPartition()
   {
	   //Setup testing variables
	   String schemeAuthority = "http://www.google.com";    //We know this is a valid scheme/authority
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   StringBuilder testBuffer = new StringBuilder();
	   String url;
	   boolean expected = true;
	   boolean result = true;
	   //Ports to check
	   ResultPair[] testPorts = {new ResultPair(":-1", false),
			   new ResultPair(":0", true),
			   new ResultPair(":65535", true),
			   new ResultPair(":65636", false)};
	   
	   //Build test URL's using known valid scheme/authority combo + test port inputs
	   for(int i = 0; i < testPorts.length; ++i) {
		   // build test URL
		   testBuffer.append(schemeAuthority);
		   testBuffer.append(testPorts[i].item);
		   expected = testPorts[i].valid;
		   url = testBuffer.toString();
		   result = urlVal.isValid(url);
		   assertEquals(url, expected, result);
		   if(expected == result) {
			   System.out.printf("isValid() PASSED: %s - Expected: %s, Result: %s\n", url, expected, result);
		   } else {
			   System.out.printf("isValid() FAILED: %s - Expected: %s, Result: %s\n", url, expected, result);
		   }
		   testBuffer = new StringBuilder();
	   }
   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
