///hdu 2222
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int type_N = 26;                  ///�ַ�������
const int maxn = 300010;                ///Trie�ϵĽڵ����
const int LEN = 60;                     ///ģ�崮����

int T, n;
char in[LEN], text[1000010];

int idx(char ch){
    return ch - 'a';
}
/****/
///const int type_N = 26;                  ///�ַ�������
///const int maxn = 300010;                ///Trie�ϵĽڵ����
///const int LEN = 60;                     ///ģ�崮����
struct Trie{
    /**/
    int nxt[maxn][type_N],              ///���ӹ�ϵ
        fail[maxn],                     ///fail
        cnt[maxn];                      ///cnt[i]: �ڵ�i�������Ĵ�����
    int sz;
    /**/
    void init(){                        ///\brief   ��ʼ��
        memset(nxt, -1, sizeof(nxt));
        memset(fail, -1, sizeof(fail));
        memset(cnt, 0, sizeof(cnt));
        sz = 1;
    }
    void insert(const char *s){         ///\brief \param ����
        int now = 0, index, tmp;
        while(*s){
            index = idx(*s);
            if(nxt[now][index] == -1){
                tmp = sz++;
                nxt[now][index] = tmp;
            }
            now = nxt[now][index];
            ++ s;
        }
        cnt[now] ++;
    }
    void Get_fail(){                    ///\brief ����AC�Զ���
        queue<int> Q;
        Q.push(0);
        int now, son, anc;
        while(!Q.empty()){
            now = Q.front();
            Q.pop();
            for(int i = 0; i < type_N; ++ i){
                son = nxt[now][i];
                if(son == -1)continue;
                Q.push(son);
                if(now == 0){
                    fail[son] = 0;
                    continue;
                }
                anc = fail[now];
                while(anc != -1){
                    if(nxt[anc][i] != -1){
                        fail[son] = nxt[anc][i];
                        break;
                    }
                    anc = fail[anc];
                }
                if(anc == -1)
                    fail[son] = 0;
            }
        }
    }
    int Match(const char *s){       ///\brief \return ��s��ģ�崮�ĳ��ִ���
        int now = 0, index, match;
        int ret = 0;
        while(*s){
            index = idx(*s);
            while(now != 0 && nxt[now][index] == -1)
                now = fail[now];
            now = nxt[now][index];
            match = now;
            if(now == -1)now = 0;
            while(match != -1){
                ret += cnt[match];
                cnt[match] = 0;
                match = fail[match];
            }
            ++ s;
        }
        return ret;
    }
    /**/
}ac;
/*****/
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        ac.init();
        scanf("%d", &n);
        while(n--){
            scanf("%s", in);
            ac.insert(in);
        }
        scanf("%s", text);
        ac.Get_fail();
        printf("%d\n", ac.Match(text));
    }
    return 0;
}
