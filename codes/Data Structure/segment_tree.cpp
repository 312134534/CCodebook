const int N=5e5+5;
int n;
int seg[N<<2],tag[N<<2];
//線段樹與懶惰標記

void merge(int idx){
    seg[idx]=seg[idx<<1]+seg[idx<<1|1];
    //區間最大要把return x+y改成max(x,y)
}

void build(int idx=1,int l=1,int r=n){//創建線段樹
    if(l==r){
        cin>>seg[idx];
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    merge(idx);
}

void push_tag(int idx,int l,int r){
    if(tag[idx]){
        int mid=(l+r)>>1;
        seg[idx<<1]+=(mid-l+1)*tag[idx];
        seg[idx<<1|1]+=(r-mid)*tag[idx];
        tag[idx<<1]+=tag[idx];
        tag[idx<<1|1]+=tag[idx];
        tag[idx]=0;
    }
}

void update_range(int ql,int qr,int val,int idx=1,int l=1,int r=n){//區間加值
    if(l!=r)
        push_tag(idx,l,r);
    if(ql<=l&&r<=qr){
        seg[idx]+=(r-l+1)*val;
        tag[idx]+=val;
        return;
    }
    int mid=(l+r)>>1;
    if(qr<=mid)
        update_range(ql,qr,val,idx<<1,l,mid);
    else if(ql>mid)
        update_range(ql,qr,val,idx<<1|1,mid+1,r);
    else{
        update_range(ql,qr,val,idx<<1,l,mid);
        update_range(ql,qr,val,idx<<1|1,mid+1,r);
    }
    merge(idx);
}

int query(int ql,int qr,int idx=1,int l=1,int r=n){//區間查詢
    if(l!=r)
        push_tag(idx,l,r);
    //ql~qr為欲查詢的範圍
    if(ql<=l&&r<=qr)
        return seg[idx];
    int mid=(l+r)>>1;
    if(mid>=qr)
        return query(ql,qr,idx<<1,l,mid);
    else if(ql>mid)
        return query(ql,qr,idx<<1|1,mid+1,r);
    else
        return query(ql,qr,idx<<1,l,mid)+query(ql,qr,idx<<1|1,mid+1,r);
        //區間最大要把return x+y改成max(x,y)
}

void update(int pos,int val,int idx=1,int l=1,int r=n){//單點更新
    if(l==r){
        seg[idx]+=val;
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid)
        update(pos,val,idx<<1,l,mid);
    else
        update(pos,val,idx<<1|1,mid+1,r);
    merge(idx);
}
