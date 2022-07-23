//
//  main.c
//  obftest01
//
//  Created by junfengtian on 2022/7/15.
//

#include <stdio.h>
// see: https://blog.quarkslab.com/deobfuscation-recovering-an-ollvm-protected-program.html
unsigned int target_function(unsigned int n)
{
  unsigned int mod = n % 4;
  unsigned int result = 0;

  if (mod == 0) result = (n | 0xBAAAD0BF) * (2 ^ n);

  else if (mod == 1) result = (n & 0xBAAAD0BF) * (3 + n);

  else if (mod == 2) result = (n ^ 0xBAAAD0BF) * (4 | n);

  else result = (n + 0xBAAAD0BF) * (5 & n);

  return result;
}


static int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}

int main(){
    printf("%d\n",add(3,4));
    printf("%d\n",sub(5,4));
    unsigned int ret = target_function(16);
    printf("hello target_function %d\n",ret);
    return 0;
}
