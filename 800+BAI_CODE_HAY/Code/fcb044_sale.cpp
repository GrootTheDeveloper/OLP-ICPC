    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
    /*vector <int> f;
    vector <int> a;

    main()
    {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int n,k;
        cin >> n >> k;
        int ai;
        for (int i=1;i<=n;i++)
        {
            cin >> ai;
            a.push_back(ai);
        }
        int res=0;
        while (a.size())
        {
            vector <int> b(f);
            auto t=a.begin();
            for (auto it=a.begin();it!=a.end();it++)
                if ((*it)>(*t)) t=it;
            int val=(*t);
            t++;
            for (auto it=a.begin();it!=t;it++)
                b.push_back(*it);
            sort(b.begin(),b.end());
            if (b.size()>=k) res+=b[k-1];
            else res+=val;
            t--;
            a.erase(t);
        }
        cout << res;

    }*/
    int a[3333];
    vector<int> b;
    main()
    {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int n,k; cin >> n >> k;
        for (int i=1;i<=n;i++)
        {
            cin >> a[i];
            if (i<n) b.push_back(a[i]);
        }
        sort(b.begin(),b.end());
        int res=0;
        for (int i=n;i>0;i--)
        {
            if (b.size()>=k && a[i]>b[k-1]) res+=b[k-1];
            else res+=a[i];
            auto t=lower_bound(b.begin(),b.end(),a[i]);
            if (i<n) b.erase(t);
        }
        cout << res;

    }











