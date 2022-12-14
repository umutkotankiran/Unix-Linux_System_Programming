// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

int getopt(int argc, char * const argv[],const char *optstring);

extern char *optarg;
extern int optind, opterr, optopt;

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <getopt.h>

int getopt_long(int argc, char * const argv[],const char *optstring,const struct option *longopts, int *longindex);
int getopt_long_only(int argc, char * const argv[], const char *optstring, const struct option *longopts, int *longindex);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <locale.h>
char* setlocale( int category, const char* locale );

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <stdio.h> 

void perror(const char *str);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------


#include <unistd.h>

char *getcwd(char *buf, size_t size);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

int chdir(const char *path);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

task_struct (files) ---> files_struct (fdt) ---> fdtable (fd) --->  file * türünden bir dizi ---> file

proses kontrol block ---> betimleyici tablosu --> dosya nesneleri (Kısaca) 

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <fcntl.h>

int open(const char *path, int flags, ...);


    O_RDONLY
    O_WRONLY
    O_RDWR
    
    S_IRUSR
    S_IWUSR
    S_IXUSR
    S_IRGRP
    S_IWGRP
    S_IXGRP
    S_IROTH
    S_IWOTH
    S_IXOTH
    
    S_IRWXU
    S_IRWXG
    S_IRWXO

    #define S_IRWXU (S_IRUSR|S_IWUSR|S_IXUSR)
    #define S_IRWXG (S_IRGRP|S_IWGRP|S_IXGRP)
    #define S_IRWXO (S_IROTH|S_IWOTH|S_IXOTH)
    
    S_IRWXU             0700        
    S_IRUSR             0400 
    S_IWUSR             0200 
    S_IXUSR             0100 
    S_IRWXG             070 
    S_IRGRP             040 
    S_IWGRP             020 
    S_IXGRP             010 
    S_IRWXO             07 
    S_IROTH             04 
    S_IWOTH             02 
    S_IXOTH             01 
    S_ISUID             04000 
    S_ISGID             02000 
    S_ISVTX             01000
    
    S_IRUSR        100 000 000
    S_IWUSR        010 000 000
    S_IXUSR        001 000 000

    S_IRGRP        000 100 000
    S_IWGRP        000 010 000
    S_IXGRP        001 001 000

    S_IROTH        000 000 100
    S_IWOTH        000 010 010
    S_IXOTH        001 001 001
    
    
    Standart C fopen                    POSIX
    "w"                                 O_WRONLY|O_CREAT|O_TRUNC
    "w+"                                O_RDWR|O_CREAT|O_TRUNC
    "r"                                 O_RDONLY
    "r+"                                O_RDWR
    "a"                                 O_WRONLY|O_CREAT|O_APPEND
    "a+"                                O_RDWR|O_CREAT|O_APPEND
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <fcntl.h>

int creat(const char *path, mode_t mode);

int creat(const char *path, mode_t mode)
{
	return open(path, O_WRONLY|O_CREAT|O_TRUNC, mode);
}

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

ssize_t read(int fd, void *buf, size_t nbyte);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t nbyte);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

off_t lseek(int fd, off_t offset, int whence);

SEEK_SET
SEEK_CUR
SEEK_END

ör : lseek(fd, 0, SEEK_END);
    
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <sys/stat.h>

mode_t umask(mode_t cmask);

   mode_t mode;

   mode = umask(0);
   umask(mode);
   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <sys/stat.h>

int stat(const char *path, struct stat *buf);
int fstat(int fd, struct stat *buf);
int lstat(const char *path, struct stat *buf);

struct stat {
        dev_t     st_dev;         /* ID of device containing file */
        ino_t     st_ino;         /* Inode number */
        mode_t    st_mode;        /* File type and mode */
        nlink_t   st_nlink;       /* Number of hard links */
        uid_t     st_uid;         /* User ID of owner */
        gid_t     st_gid;         /* Group ID of owner */
        dev_t     st_rdev;        /* Device ID (if special file) */
        off_t     st_size;        /* Total size, in bytes */
        blksize_t st_blksize;     /* Block size for filesystem I/O */
        blkcnt_t  st_blocks;      /* Number of 512B blocks allocated */

        /* Since Linux 2.6, the kernel supports nanosecond precision for the following timestamp fields.
           For the details before Linux 2.6, see NOTES. */

        struct timespec st_atim;  /* Time of last access */
        struct timespec st_mtim;  /* Time of last modification */
        struct timespec st_ctim;  /* Time of last status change */

    #define st_atime st_atim.tv_sec      /* Backward compatibility */
    #define st_mtime st_mtim.tv_sec
    #define st_ctime st_ctim.tv_sec
    };

   struct timespec {
        time_t  tv_sec;      
        long    tv_nsec;
    };


    S_ISBLK(m)      Blok aygıt sürücü dosyası mı? (ls -l'de 'b' dosya türü)
    S_ISCHR(m)      Karakter aygıt sürücü dosyası mı? (ls -l'de 'c' dosya türü)
    S_ISDIR(m)      Dizin dosyası mı? (ls -l'de 'd' dosya türü)
    S_ISFIFO(m)     Boru dosyası mı? (ls -l'de 'p' dosya türü)
    S_ISREG(m)      Sıradan bir disk dosyası mı? (ls -l'de '-' dosya türü)
    S_ISLNK(m)      Sembolik bağlantı dosyası mı? (ls -l'de 'l' dosya türü)
    S_ISSOCK(m)     Soket dosyası mı? (ls -l'de 's' dosya türü)
	
    S_IFBLK         Blok aygıt dosyası
    S_IFCHR         Karakter aygıt dosyası
    S_IFIFO         Boru dosyası
    S_IFREG         Sıradan disk dosyası
    S_IFDIR         Dizin dosyası
    S_IFLNK         Sembolik bağlantı dosyası
    S_IFSOCK        Soket dosyası
    
    S_IFMT
    
    (mode & S_IFMT) == S_IFXXX


// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------


#include <stdio.h>

int remove(const char *path);       

#include <unistd.h>

int unlink(const char *path);

remove'da unlink'te aynı işi yapıyor.
remove C fonksiyonudur. unlink ise POSIX fonksionudur
    
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <sys/stat.h>

int chmod(const char *path, mode_t mode);
int fchmod(int fd, mode_t mode);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	#ifdef _POSIX_CHOWN_RESTRICTED
	 	printf("chown restricted\n");
	#else
		printf("chown not restricted\n");
	#endif

	return 0;
}


// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

int chown(const char *path, uid_t owner, gid_t group);  
int fchown(int fd, uid_t owner, gid_t group);   

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <sys/stat.h>

int mkdir(const char *path, mode_t mode);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

int rmdir(const char *path);  

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <pwd.h>

struct passwd *getpwnam(const char *name);
struct passwd *getpwuid(uid_t uid);


struct passwd {
        char   *pw_name;       /* username */
        char   *pw_passwd;     /* user password */
        uid_t   pw_uid;        /* user ID */
        gid_t   pw_gid;        /* group ID */
        char   *pw_gecos;      /* user information */
        char   *pw_dir;        /* home directory */
        char   *pw_shell;      /* shell program */
    };

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <pwd.h>

struct passwd *getpwent(void);
void setpwent(void);
void endpwent(void);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <grp.h>

struct group *getgrnam(const char *name);
struct group *getgrgid(gid_t gid);
struct group *getgrent(void);
void setgrent(void);
void endgrent(void);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <fcntl.h>

int openat(int fd, const char *path, int oflag, ...);

Fonksiyonun prototipini open fonksiyonu ile karşılaştırınız:

int open(const char *path, int oflag, ...);


// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

int fchmodat(int fd, const char *path, mode_t mode, int flag);
int fchownat(int fd, const char *path, uid_t owner, gid_t group, int flag);
int fstatat(int fd, const char *restrict path, struct stat *restrict buf, int flag);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------


#include <dirent.h>

DIR *opendir(const char *dirname);

DIR *fdopendir(int fd);

struct dirent *readdir(DIR *dirp);

int closedir(DIR *dirp);


struct dirent {
        ino_t          d_ino;       /* Inode number */
        off_t          d_off;       /* Not an offset; see below */
        unsigned short d_reclen;    /* Length of this record */
        unsigned char  d_type;      /* Type of file; not supported
                                        by all filesystem types */
        char           d_name[256]; /* Null-terminated filename */
};

    DT_BLK      block device
    DT_CHR      character device
    DT_DIR      directory
    DT_FIFO     named pipe (FIFO)
    DT_LNK      symbolic link
    DT_REG      regular file.
    DT_SOCK     UNIX domain socket.
    DT_UNKNOWN  Bilinmeyen bir tür

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <dirent.h>

int dirfd(DIR *dirp);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <sys/stat.h>

int fstatat(int fd, const char *restrict path, struct stat *restrict buf, int flag);

Fonskiyonun fd parametresinin yanı sıra aynı zamanda bir flag parametresinin olduğuna dikkat ediniz. Bu parametre stat semantiğinin mi yoksa 
lstat semantiğinin mi uygulanacağını belirtmektedir. Eğer bu parametreye 0 geçilirse bu durumda stat semnatiği uygulanır Eğer bu parametreye 
AT_SYMLINK_NOFOLLOW değeri geçilirse bu durumda lstat semantiği uygulanmaktadır. AT_SYMLINK_NOFOLLOW sembolik sabiti <sys/stat.h> içerisinde değil
<fcntl.h> içerisinde bildirilmiştir. İşte biz yukarıdaki örnekte önce dizin'in betimleycisini dirfd fonksiyonu ile alıp bunu fstatat 
fonksiyonunda kullanırsak yol ifadesini düzenlememize gerek kalmaz. Aşağıdaki örnekte bu çözüm verilmiştir.

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <dirent.h>

long telldir(DIR *dirp);
void seekdir(DIR *dirp, long loc);
void rewinddir(DIR *dirp);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <dirent.h>

int alphasort(const struct dirent **d1, const struct dirent **d2);
int scandir(const char *dir, struct dirent ***namelist, int (*sel)(const struct dirent *),
	int (*compar)(const struct dirent **, const struct dirent **));  
	
int cmp(const struct **direnet1, const struct **dirent2); -> biz yazdık bunu

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#define _XOPEN_SOURCE 500

#include <ftw.h>

int nftw(const char *path, int (*fn)(const char *, const struct stat *, int, struct FTW *), int fd_limit, int flags);


	FTW_CHDIR: Eğer bu bayrak belirtilirse fonksiyon her dizine geçtiğinde prosesin çalışma dizinini de o dizin olarak değiştirmektedir. 

	FTW_DEPTH: Normalde dolaşım "pre-order" biçimde yapılmaktadır. Bu bayrak girilirse "post-order" dolaşım yapılır. Bayrağın ismi 
	yanlış 	verilmiştir. "pre-order" dolaşım demek bir dizin ile karşılaşıldığında önce dizin girişinin ele alnıması sonra özyineleme
	yapılması demektir. "post-order" dolaşım ise önce özyineleme yapılıp sonra dizin girişinin ele alınması demektir.
	Default durum "pre-order" dolaşım biçimindedir. 

	FTW_MOUNT: Bu bayrak belirtilirse özyineleme yapılırken bir "mount point" ile karşılaşılırsa o dosya sistemine girilmez. Default durumda 
	özyineleme sırasında bir "mount point" ile kaşılaşılırsa özyineleme o dosya sisteminin içime girilerek devam ettirilmektedir. 

	FTW_PHYS:  Default durumda nftw fonksiyonu bir sembolik link dosyası ile karşılaştığında linki izler ve link'in hedefine
	yönelik hareket eder. Daha önce bir böyle bir durumun sonsuz döngüye yol açabileceğinden bahsetmiştik. Bu nedenle biz özyinelemede 
	stat fonksiyonu yerine lstat fonksiyonunu kullanmıştık. İşte bu bayrak belirtilirse artık nftw fonksiyonu sembolik link dosyası
	ile karşılaştığında link'i izlemez, sembolik link dosyasının kendisi hakkında bilgi verir. 





int callback(const char *path, const struct stat *finfo, int flag, struct FTW *ftw);  -> biz yazdık

	struct FTW {
		int base;
		int level;
	};

	FTW_D: Bulunan giriş bir dizin girişidir.

	FTW_DNR: Bulunan giriş bir dizin girişidir. Ancak bu dizin'in içi okunamamaktadır. Dolayısıyla bu dizin özyinelemede dolaşılamayacaktır.

	FTW_DP: Post-order dolaşımda bir dizinle karşılaşıldığında bayrak FTW_D yerine FTW_DP olarak set edilmektedir. 

	FTW_F: Bulunan dizin girişi sıradan bir dıosyadır (regular file).

	FTW_NS: Bulunan dizin girişi için stat ya da lstat fonksiyonu başarısız olmuştur. Dolayısıyla fonksiyona geçirilen stat yapısı da
	anlamlı değildir. 

	FTW_SL: Bulunan giriş bir sembolik bağlantı dosyasına ilişkindir. Sembolik bağlantı dosyasının hedefi mevcuttur. 

	FTW_SLN: Bulunan giriş bir sembolik bağlantı dosyasına ilişkindir. Sembolik bağlantı dosyasının hedefi mevcut değildir ("danging klink" durumu). 

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

int link(const char *oldpath, const char *newpath);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <fcntl.h>

int linkat(int fd1, const char *path1, int fd2, const char *path2, int flag);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

int symlink(const char *path1, const char *path2);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <fcntl.h>

int symlinkat(const char *path1, int fd, const char *path2);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

ssize_t readlink(const char *path, char *buf, size_t bufsize);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

int access(const char *path, int amode) 

	Fonksiyonun birinci parametresi erişim testinin yapılacağı dosyanın yol ifadesini belirtmektedir. İkinci parametresi test edilecek 
	erişimi belirtir. Bu parametre aşağıdaki sembolik sabitlerin bir düzeyinde OR'lanmasıyla oluşturulabilir:

	R_OK: Okuma yapılabilir mi?
	W_OK: Yazma yapılabilir mi?
	X_OK: Çalıştırılabilir mi?
	F_OK: Dosya var mı?

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <unistd.h>

int euidaccess(const char *pathname, int mode);
int eaccess(const char *pathname, int mode);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <fcntl.h>

int faccessat(int fd, const char *path, int amode, int flag);

    Fonksiyonun birinci paraetresi ikinci parametresiyle belirtilen yol ifadesinin göreli olması durumunda aramanın yapılacağı 
    dizini belirtmektedir. Son parametre 0 geçilebilir ya da AT_EACCESS geçilebilir. Bu AT_EACCESS değeri test işleminin etkin kulalnı ve grup 
    id'lerine bakılarak yapılacağı anlamına gelmektedir. (Tabii ikinci parametre ile belirtilen yol ifadesi mutlak olduğunda birinci parametrede 
    belirtilen dizine ilişkin betimleyici yine dikkate alınmaz. Ancak üçüncü parametreyle belirtilen bayrak dikkate alınır)

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

int dup(int fildes);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

#include <unistd.h>

int dup2(int fildes, int fildes2);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

IO yönlendirmesi kabuk üzerinden de yapılabilmektedir. Kabukta ">" sembolü 1 numaralı betimleyicinin yönlendirileceği anlamına gelmektedir.
						   
Kabuk üzerinde "<" sembolü de 0 numaralı betimleyiciyi yönlendirmektedr.						   
						   
Aslında kabukta genel olarak yönlendirme için "n>" ve "n<" sembolleri de kullanılabilmektedir. Buradaki n betimleyicinin 
numarasını belirtir. Bu sayede biz herhangi bir betimleyiciyi okuma ve yazma amaçlı bir dosyaya yönlendirebiliriz.
ÖR: ./sample 2> test.txt

Tabii hem stdout dosyasını hem de stdin dosyasını kabuk üzerinden birlikte de yönlendirebiliriz. 
ÖR: ./sample > out.txt < in.txt
							   
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------						   

