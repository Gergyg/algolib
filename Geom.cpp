struct P {
    ll x, y;

    P operator-(const P& b) const{
        return {x - b.x, y - b.y};
    }

    void operator-=(const P& b){
        *this = *this - b;
    }

    ll operator*(const P& b) const{
        return x * b.y - b.x * y;
    }

    ll triangle(const P& b, const P& c) const{
        return (b - *this) * (c - *this);
    }

    bool operator<(const P& b){
        if(x == b.x) return y < b.y;
        else return x < b.x;
    }
};

istream &operator >> (istream &in, P &p) { return in >> p.x >> p.y; }

bool is_intersect(vector<P> a){

    if((a[1] - a[0]) * (a[3] - a[2]) == 0){
        if(a[0].triangle(a[1], a[2]) != 0){
            return false;
        }

        for(ll i=0; i<2; i++){
            if(max(a[0].x, a[1].x) < min(a[2].x, a[3].x) || max(a[0].y, a[1].y) < min(a[2].y, a[3].y)){
                return false;
            }
            swap(a[0], a[2]);
            swap(a[1], a[3]);
        }
        return true;
    }

    for(ll i=0; i<2; i++){
        ll s1 = a[0].triangle(a[1], a[2]);
        ll s2 = a[0].triangle(a[1], a[3]);

        if(s1 > 0 && s2 > 0 || s1 < 0 && s2 < 0) return false;
        swap(a[0], a[2]);
        swap(a[1], a[3]);
    }

    return true;

}

bool is_on_seg(const P& p, const P& a, const P& b){
    return  p.triangle(a, b) == 0 
            && min(a.x, b.x) <= p.x 
            && max(a.x, b.x) >= p.x 
            && max(a.y, b.y) >= p.y
            && min(a.y, b.y) <= p.y;
}

ll double_area(const vector<P>& a){
    ll s = 0;

    for(ll i=2; i<a.size(); i++){
        s += a[0].triangle(a[i-1], a[i]);
    }

    return abs(s);
}

vector<P> convex_hull(vector<P> a){

    ll n = a.size();

    sort(a.begin(), a.end());

    vector<P> hull;
    
    for(ll rep = 0; rep < 2; rep++){
        ll Sv = hull.size();
        for(ll i=0; i<n; i++){
            while(hull.size() - Sv >= 2){
                
                P A = hull[hull.size() - 2];
                P B = hull[hull.size() - 1];

                if(A.triangle(B, a[i]) <= 0) break;
                hull.pop_back();

            }

            hull.pb(a[i]);
        }

        hull.pop_back();

        reverse(a.begin(), a.end());
    }

    return hull;
}