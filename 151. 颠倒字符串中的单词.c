char * reverseWords(char * s){
    int len,i,k,newlen,key,slow,fast;
    char *str;
    len=strlen(s);
    newlen=0;
    key=0;//*用来指示是否为多余空格的*
    for(i=0;i<len;++i)
    {
        if(s[i]!=' ')
        {
            ++newlen;
            key=1;
        }else if(s[i]==' '&&key==1)//*表明该处为单词后的空格，长度加一*
        {
            ++newlen;
            key=0;
        }
    }
    if(key==0)//*最后会多出一个末端空格长度，所以计算长度减一*
    {
        --newlen;
    }
    str=(char*)malloc((newlen+1)*sizeof(char));
    fast=slow=len-1;
    k=0;
    while(fast>=0)
    {
        while(fast>=0&&s[fast]==' ')//*找到对应单词的末尾*
        {
            --fast;
        }
        slow=fast;
        while(fast>=0&&s[fast]!=' ')//*找到对应单词的头部*
        {
            --fast;
        }
        for(i=fast+1;i<=slow;++i)//*对应导入*
        {
            str[k++]=s[i];
        }
        if(k<newlen)//*最后一个空格输入舍去*
        {
            str[k++]=' ';
        }
    }
    str[k]='\0';
    return str;
}
