// #ifndef __USER__

struct stat;
struct rtcdate;
struct lock;
// typedef struct lock{
//   uint flag;
// }lock;

// system calls
int clone(void*, void (*func)(void*, void*), void*, void*);
int join(int);
int lock_init(struct lock*);
void lock_acquire(struct lock*);
void lock_release(struct lock*);
int fork(void);
int exit(void) __attribute__((noreturn));
int wait(void);
int pipe(int*);
int write(int, const void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(char*, char**);
int open(const char*, int);
int mknod(const char*, short, short);
int unlink(const char*);
int fstat(int fd, struct stat*);
int link(const char*, const char*);
int mkdir(const char*);
int chdir(const char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);

// ulib.c
int thread_create(void (*worker)(void *, void *), void *arg1, void *arg2);
int user_lock_init(struct lock*);
void user_lock_acquire(struct lock*);
void user_lock_release(struct lock*);
int stat(const char*, struct stat*);
char* strcpy(char*, const char*);
void *memmove(void*, const void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void printf(int, const char*, ...);
char* gets(char*, int max);
uint strlen(const char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);

// #endif