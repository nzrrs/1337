#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define G "\033[32mOK\033[0m"
#define R "\033[31mKO\033[0m"

char *ft_strdup(const char *s1);

static void run(const char *name, const char *s)
{
	char *exp = strdup(s);
	char *got = ft_strdup(s);
	int content = 0, ptr = 0, len = 0;
	char diff[128] = "-";

	if (!got)
		snprintf(diff, sizeof diff, "ft_strdup returned NULL");
	else
	{
		content = (strcmp(exp, got) == 0);
		ptr = (got != s && got != exp);
		len = (strlen(exp) == strlen(got));
		if (!content)
		{
			size_t i = 0;
			while (exp[i] && exp[i] == got[i])
				i++;
			snprintf(diff, sizeof diff, "idx %zu: expected '%c'(%d) got '%c'(%d)",
				i, exp[i] ? exp[i] : '0', exp[i], got[i] ? got[i] : '0', got[i]);
		}
		else if (!ptr)
			snprintf(diff, sizeof diff, "same pointer as source (no malloc)");
		else if (!len)
			snprintf(diff, sizeof diff, "len expected %zu got %zu", strlen(exp), strlen(got));
	}
	printf("| %-16s | %-7s | %-7s | %-7s | %s\n", name,
		content ? G : R, ptr ? G : R, len ? G : R, diff);
	free(exp);
	free(got);
}

int main(void)
{
	char big[10001];

	memset(big, 'a', 10000);
	big[10000] = '\0';
	printf("| %-16s | %-4s | %-4s | %-4s | %s\n", "TEST", "CONTENT", "NEW PTR", "LEN", "DIFF");
	printf("|------------------|---------|---------|---------|-----------\n");
	run("normal", "hello");
	run("empty", "");
	run("1 char", "a");
	run("spaces/tab/nl", "with spaces\tand\ttabs\nnewline");
	run("special chars", "42 !@#$%^&*()_+{}|:<>?");
	run("big (10000)", big);
	return 0;
}
