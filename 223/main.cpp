class Solution {
public:
    int intersect(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (B >= H || D <= F) return 0;
        if (A >= G || C <= E) return 0;
        return (min(D, H)-max(B, F)) * (min(G, C)-max(A, E));
    }

    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return (D-B)*(C-A) + (H-F)*(G-E) - intersect(A, B, C, D, E, F, G, H);
    }
};