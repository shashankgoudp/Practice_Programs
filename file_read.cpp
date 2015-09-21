#include<stdio.h>
#include<string.h>



//
//	int main()
//	{
//    		FILE *ptr_file;
//    		char buf[1000];
//
//    		ptr_file =fopen("F:\ThirdSem\Computer Graphics\js_webgl\js\test.txt","r");
//    		if (!ptr_file)
//        		return 1;
//
//    		while (fgets(buf,1000, ptr_file)!=NULL)
//        		printf("%s",buf);
//
//			fclose(ptr_file);
//    		return 0;
//	}
	int main()
	{
		FILE *fp;
//		int x;
//
//		ptr_file =fopen("F:\ThirdSem\Computer Graphics\js_webgl\js\test.txt","r");
//
//		if (!ptr_file)
//			return 1;
//
//		for (x=1; x<=10; x++)
//			fprintf(ptr_file,"%d\n", x);
//
//		fclose(ptr_file);
//
//		return  0;
		
		fprintf(fp, "This is testing for fprintf...\n");
  		fputs("This is testing for fputs...\n", fp);
  		 fclose(fp);
	}

