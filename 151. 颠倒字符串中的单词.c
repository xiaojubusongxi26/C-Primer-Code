char * reverseWords(char * s){
    int len,i,k,newlen,key,slow,fast;
    char *str;
    len=strlen(s);
    newlen=0;
    key=0;//*����ָʾ�Ƿ�Ϊ����ո��*
    for(i=0;i<len;++i)
    {
        if(s[i]!=' ')
        {
            ++newlen;
            key=1;
        }else if(s[i]==' '&&key==1)//*�����ô�Ϊ���ʺ�Ŀո񣬳��ȼ�һ*
        {
            ++newlen;
            key=0;
        }
    }
    if(key==0)//*������һ��ĩ�˿ո񳤶ȣ����Լ��㳤�ȼ�һ*
    {
        --newlen;
    }
    str=(char*)malloc((newlen+1)*sizeof(char));
    fast=slow=len-1;
    k=0;
    while(fast>=0)
    {
        while(fast>=0&&s[fast]==' ')//*�ҵ���Ӧ���ʵ�ĩβ*
        {
            --fast;
        }
        slow=fast;
        while(fast>=0&&s[fast]!=' ')//*�ҵ���Ӧ���ʵ�ͷ��*
        {
            --fast;
        }
        for(i=fast+1;i<=slow;++i)//*��Ӧ����*
        {
            str[k++]=s[i];
        }
        if(k<newlen)//*���һ���ո�������ȥ*
        {
            str[k++]=' ';
        }
    }
    str[k]='\0';
    return str;
}
