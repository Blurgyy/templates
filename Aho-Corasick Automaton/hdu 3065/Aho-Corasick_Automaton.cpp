//HDU 3065 
///若有重合串则多次计数，模板串中只有大写英文字母，文本串中出现了别的字符。
///这时只要遇到不是大写字母的字符就将now赋为&root，++ s并continue即可。不影响计数
///答案用map存储

///多组输入！！！马的这题耍流氓不说多组于是我莫名WA

#include<cstdio>
#include<cstring>
#include<malloc.h>
#include<queue>
#include<map>
const int maxn = 2000010;

struct Trie
{
    Trie *nxt[26], *fail;
    int id;
    void init(){
        for(int i = 0; i < 26; ++ i)
            nxt[i] = NULL;
        fail = NULL;
        id = 0;
    }
}root;
int N;
char word[1010][55], text[maxn];
std::map<int, int> out;

void Insert(char *s, int ID){
    Trie *now = &root, *tmp;
    int index;
    while(*s){
        index = *s - 'A';
        if(!now->nxt[index]){
            tmp = (Trie*)malloc(sizeof(Trie));
            tmp->init();
            now->nxt[index] = tmp;
        }
        now = now->nxt[index];
        ++ s;
    }
    now->id = ID;
}

void Get_fail(){
    std::queue<Trie*> Q;
    Trie *now, *ancestor;
    Q.push(&root);
    while(!Q.empty()){
        now = Q.front();
        Q.pop();
        for(int i = 0; i < 26; ++ i){
            if(now->nxt[i]){
                Q.push(now->nxt[i]);
                if(now == &root){
                    now->nxt[i]->fail = now;
                    continue;
                }
                ancestor = now->fail;
                while(ancestor){
                    if(ancestor->nxt[i]){
                        now->nxt[i]->fail = ancestor->nxt[i];
                        break;
                    }
                    ancestor = ancestor->fail;
                }
                if(!ancestor)
                    now->nxt[i]->fail = &root;
            }
        }
    }
}

void AC_Automation(char *s){
    Get_fail();
    Trie *now = &root, *match;
    int index;
    while(*s){
        if(*s < 'A' || *s > 'Z'){
            now = &root;
            ++ s;
            continue;
        }
        index = *s - 'A';
        while(!now->nxt[index] && now != &root)
            now = now->fail;
        now = now->nxt[index];
        if(!now)now = &root;
        match = now;
        while(match){
            if(match->id){
                ++ out[match->id];
            }
            match = match->fail;
        }
        ++ s;
    }
}

void Del(Trie *now = &root){
    for(int i = 0; i < 26; ++ i){
        if(now->nxt[i]){
            Del(now->nxt[i]);
            free(now->nxt[i]);
        }
    }
}

int main(){
    while(~scanf("%d", &N)){
        root.init();
        out.clear();
        for(int i = 1; i <= N; ++ i){
            scanf("%s", word[i]);
            Insert(word[i], i);
        }
        scanf("%s", text);
        AC_Automation(text);
        for(std::map<int, int>::iterator i = out.begin(); i != out.end(); ++ i)
            printf("%s: %d\n", word[(*i).first], (*i).second);
        Del();
    }
    return 0;
}