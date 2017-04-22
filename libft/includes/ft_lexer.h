#ifndef FT_LEXER
# define FT_LEXER

# include "libft.h"


struct                      s_lexem
{
    int                     id;
    char                    *key;
    char                    *value;
    int                     size;
    int                     li;
    int                     co;
};

struct                      s_analyzer
{
    int                     id;
    char                    *key;
    char                    *regex;
    t_nfa                   *nfa;
};

struct                      s_lexer
{
    char                    **regex;
    char                    **key;
    t_list                  *analyzer;
    int                     size;
};

t_lexer                     *ft_gen_lex(char **regex, char **key, int size);
void                        ft_set_lex(t_lexer *lexer);
void                        ft_quit_lex(void);
void                        ft_kill_lex(void);

void                        ft_lex_start_scan(char *scan);
t_lexem                     *ft_lex_eval(void);
t_lexem                     *ft_lex(void);
void                        lexem_dump(t_lexem *lexem);
void                        lexem_del(t_lexem **lexem);

t_lexer                     *lexer_new(char **regex, char **key, int size);
int                         lexer_add(t_lexer *lexer, char *regex, char *key);
int                         lexer_computize(t_lexer *lexer);
void                        lexer_del(t_lexer **lexer);


#endif
