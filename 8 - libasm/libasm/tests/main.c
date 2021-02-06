/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:32:33 by curreg            #+#    #+#             */
/*   Updated: 2020/11/01 00:20:11 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../libasm.h"

int main(void)
{
    char    *empty_str;
    char    *long_str;
    char    buf[100];
    int     fd;
    int     ft_fd;

    empty_str = "";
    long_str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    printf("\n================================\n");
	printf("========== FT_STRLEN ===========\n");
	printf("================================\n\n");
    printf("original: %lu\n", strlen(empty_str));
    printf("custom  : %lu\n", ft_strlen(empty_str));
    printf("original: %lu\n", strlen(long_str));
    printf("custom  : %lu\n", ft_strlen(long_str));

    printf("\n================================\n");
	printf("========== FT_STRCPY ===========\n");
	printf("================================\n\n");
    printf("original: >%s<\n", strcpy(buf, empty_str));
    printf("custom  : >%s<\n", ft_strcpy(buf, empty_str));
    printf("original: %s\n", strcpy(buf, long_str));
    printf("custom  : %s\n", ft_strcpy(buf, long_str));

    printf("\n================================\n");
	printf("========== FT_STRCMP ===========\n");
	printf("================================\n\n");
    printf("original: %d\ncustom  : %d\n", strcmp("", ""), ft_strcmp("", ""));
    printf("original: %d\ncustom  : %d\n", strcmp("", "abc"), ft_strcmp("", "abc"));
    printf("original: %d\ncustom  : %d\n", strcmp("abc", ""), ft_strcmp("abc", ""));
    printf("original: %d\ncustom  : %d\n", strcmp("abc", "cda"), ft_strcmp("abc", "cda"));
    printf("original: %d\ncustom  : %d\n", strcmp("cda", "abc"), ft_strcmp("cda", "abc"));
    printf("original: %d\ncustom  : %d\n", strcmp("abcd", "abc"), ft_strcmp("abcd", "abc"));
    printf("original: %d\ncustom  : %d\n", strcmp("    ", " cda"), ft_strcmp("    ", " cda"));
    printf("original: %d\ncustom  : %d\n", strcmp("\xff\x80", "\xff\x00"), ft_strcmp("\xff\x80", "\xff\x00"));
    printf("original: %d\ncustom  : %d\n", strcmp("\xff\xfe", "\xff"), ft_strcmp("\xff\xfe", "\xff"));
    printf("original: %d\ncustom  : %d\n", strcmp("\xff", "\xff\xfe"), ft_strcmp("\xff", "\xff\xfe"));
    printf("original: %d\ncustom  : %d\n", strcmp("1", "2"), ft_strcmp("1", "2"));
    
    printf("\n================================\n");
	printf("========== FT_WRITE ============\n");
	printf("================================\n\n");
    
    char    *str = "1234567";
    fd = open("./tests/text.txt", O_CREAT | O_RDWR, 0666);
    ft_fd = open("./tests/ft_text.txt",O_CREAT | O_RDWR, 0666);
    
    write(1, "original: ", 10);
    write(1, str, 7);
    write(1, "\n", 1);
    write(1, "custom  : ", 10);
    ft_write(1, str, 7);
    write(1, "\n", 1);
    write(fd, str, 7);
    ft_write(ft_fd, str, 7);
    printf(">>>> write file!\n");
    printf("original: error: %zd, %s\n", write(21, str, 7), strerror(errno));
    printf("custom  : error: %zd, %s\n", ft_write(21, str, 7), strerror(errno));
    close(fd);
    close(ft_fd);

    printf("\n================================\n");
	printf("========== FT_READ =============\n");
	printf("================================\n\n");
    fd = open("./tests/text.txt", O_RDONLY);
    ft_fd = open("./tests/ft_text.txt", O_RDONLY);
    read(fd, buf, 7);
    printf("original: %s\n", buf);
    ft_read(ft_fd, buf, 7);
    printf("custom  : %s\n", buf);
    printf("original: error: %zd, %s\n", read(21, buf, 7), strerror(errno));
    printf("custom  : error: %zd, %s\n", ft_read(21, buf, 7), strerror(errno));

    printf("\n================================\n");
	printf("========== FT_STRDUP ===========\n");
	printf("================================\n\n");
    printf("original: >%s<\n", strdup(empty_str));
    printf("custom  : >%s<\n", ft_strdup(empty_str));
    printf("original: %s\n", strdup(long_str));
    printf("custom  : %s\n", ft_strdup(long_str));

    return (0);
}