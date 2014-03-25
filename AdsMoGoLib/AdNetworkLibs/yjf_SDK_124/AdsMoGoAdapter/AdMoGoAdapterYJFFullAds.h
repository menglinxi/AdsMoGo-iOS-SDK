//
//  AdMoGoAdapterYJFFullAds.h
//  TestMOGOSDKAPP
//
//  Created by mogo_wenyand on 13-4-9.
//
//
#import "AdMoGoAdNetworkAdapter.h"
#import <Escore/YJFInterstitial.h>






@interface AdMoGoAdapterYJFFullAds : AdMoGoAdNetworkAdapter<YJFInterstitialDelegate>{
    NSTimer *timer;
    BOOL isStop;
    YJFInterstitial *_interstitial;
    BOOL isStopTimer;
    BOOL isReady;
}
+ (AdMoGoAdNetworkType)networkType;
- (void)getAd;
- (void)stopBeingDelegate;
- (void)stopTimer;
- (void)stopAd;
- (void)dealloc;
@end
