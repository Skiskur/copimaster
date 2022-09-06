#ifndef UTIL_H
#define UTIL_H

#include <sys/types.h>

#define kUMASK_OPTIONS_MAX_SZ 10

struct CopymasterOptionsLseek {
    int x;
    off_t pos1;
    off_t pos2;
    size_t num;
};

struct CopymasterOptions {
    const char * infile;
    const char * outfile;
    int fast;
    int slow;
    int create;
    mode_t create_mode;
    int overwrite;
    int append;
    int lseek;
    struct CopymasterOptionsLseek lseek_options;
    int directory;
    int delete_opt;
    int chmod;
    mode_t chmod_mode;
    int inode;
    ino_t inode_number;
    int umask;
    char umask_options[kUMASK_OPTIONS_MAX_SZ][4];
    int link;
    int truncate;
    off_t truncate_size;
    int sparse;
};

struct CopymasterOptions ParseCopymasterOptions(int argc, char *argv[]);

void FatalError(char c, const char* msg, int exit_status);

void slow(const char * infile,const char * outfile);

void fast(const char * infile,const char * outfile);

void create(const char * infile,const char * outfile);

void overwrite(const char * infile,const char * outfile);

void append(const char * infile,const char * outfile);

void lseek(const char * infile,const char * outfile);

void directory(const char * infile,const char * outfile);

void delete_opt(const char * infile,const char * outfile);

void chmod(const char * infile,const char * outfile);

void link(const char * infile,const char * outfile);

void truncate(const char * infile,const char * outfile);

void inode(const char * infile,const char * outfile);

void umask(const char * infile,const char * outfile);

void sparse(const char * infile,const char * outfile);

#endif /* UTIL_H */
