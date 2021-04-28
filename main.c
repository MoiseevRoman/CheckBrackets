#include <stdio.h>
#include <stdlib.h>


int main( int argc, char *argv[] )
{

    FILE * input;
    if((input = fopen(argv[1], "r")) == NULL)
    {
        printf("ERROR with input\n");
    }
    char vv =0;
    char cha=0;
    int rou = 0;
    int rou_ = 0;// poryadok cryglih
    int qua = 0;
    int qua_ = 0;// poryadok qvadratnih
    int fig = 0;
    int fig_ = 0;  // poryadok figurnih
    int pr = 0;
    int por = 0; //poryadok skobok
    printf("Choice type of brackets:((,[,{,a):\n",'%s');
    scanf("%c",&vv);
    while((cha = getc(input))!= EOF){
        if((cha == '"')||(cha =='\'')) {
            while (((cha = getc(input)) !='"')&&((cha = getc(input)) !='\'')){
                if(cha!= EOF){
                    continue;}
                else break;
            }
        }
            switch(cha){
                case '(':
                    if((vv=='(')||(vv == 'a')){
                        rou++;
                        por++;
                        rou_ = por;
                        }
                    break;
                case '{':
                    if((vv=='{')||(vv == 'a')){
                        fig++;
                        por++;
                        fig_ = por;
                        }
                    break;
                case '[':
                    if((vv=='[')||(vv == 'a')){
                        qua++;
                        por++;
                        qua_ = por;
                        }
                    break;
                case ')':
                    if((vv=='(')||(vv == 'a')){
                        rou--;
                        if(((rou<qua)&&(rou_<qua_))||((rou<fig)&&(rou_<fig_))){
                            pr++;}
                        }
                    break;
                case '}':
                    if((vv=='{')||(vv == 'a')){
                        fig--;
                        if(((fig<qua)&&(fig_<qua_))||((fig<rou)&&(fig_<rou_))){
                            pr++;}
                        }
                    break;
                case ']':
                    if((vv=='[')||(vv == 'a')){
                        qua--;
                        if(((qua<rou)&&(qua_<rou_))||((qua<fig)&&(qua_<fig_))){
                            pr++;}
                            }
                    break;
            }
    }
    if((rou !=0)||(fig!=0)||(qua!=0)){
        pr++;
    }
    if(pr>0){
        printf("ERROR");
    }
    return 0;
}
