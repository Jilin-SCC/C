#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define CLEAR() printf("\033[2J")
pthread_t ntid;

void printids(const char *s)
{
	pid_t      pid;
	pthread_t  tid;

	pid = getpid();
	tid = pthread_self();
	printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int)pid,
	       (unsigned int)tid, (unsigned int)tid);
}

void *thr_fn(void *arg)
{
	printids(arg);
	for (int i = 0; i < 10; ++i)
	{
		sleep(1);
		printf("%d：%s\n", i,"我爱祖国的蓝天！");
	}
	return NULL;
}

int main(int argc, char const *argv[])
{
	
	int command;
	int err;
	
	while(1)
		{
			CLEAR();
			printf("%s\n", "===================[命 令 菜 单]===================");
			printf("%s\n", "     1.退   出        2.开启线程      3.打印主线程   ");
			printf("%s\n", "     4.清除密码        5.测试读写      6.内存检测    ");
			printf("%s\n", "     7.清除密码        8.测试读写      9.内存检测    ");
			printf("%s\n", "===================[命 令 菜 单]===================");
			printf("%s\n", "请出入：");
			scanf("%d",&command);
			switch (command)
			{
				case 1:
				return 0;
				break;
				case 2:				
					err = pthread_create(&ntid, NULL, thr_fn, "new thread: ");
					if (err != 0) 
					{
						fprintf(stderr, "can't create thread: %s\n", strerror(err));
						exit(1);
					}
					pthread_join(ntid,NULL);
				break;
				case 3:
				printids("main thread:");
				break;
			}
			sleep(3);
		}
	return 0;
}