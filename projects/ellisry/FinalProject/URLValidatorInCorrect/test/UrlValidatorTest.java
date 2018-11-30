

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
   
   public void testSchemePartition(){
	   
	   //Setup testing variables
	   String authority = "www.google.com";    // We know this is a valid authority
	   UrlValidator urlVal = new UrlValidator();    // initializes validator with default schemes - http, https and ftp
	   StringBuilder testBuffer = new StringBuilder();
	   String url;
	   boolean expected = true;
	   boolean result = true;
	   
	   // Schemes to check
	   ResultPair[] testSchemes = {new ResultPair("http", false),
			   new ResultPair("http:/", true),
			   new ResultPair("http://", true)};
	   
	   //Build test URL's using test schemes + known valid authority
	   for(int i = 0; i < testSchemes.length; ++i) {
		   // build test URL
		   testBuffer.append(testSchemes[i].item);
		   testBuffer.append(authority);
		   expected = testSchemes[i].valid;
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
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
