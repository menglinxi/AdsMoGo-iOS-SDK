//
//  AdMoGoAdapterPuchBox.h
//  wanghaotest
//
//  Created by MOGO on 13-9-28.
//
//

#import "AdMoGoAdNetworkAdapter.h"
#import "PBBannerView.h"
#import "PunchBoxAd.h"
//#import "PunchBoxAdDelegate.h"
@interface AdMoGoAdapterPuchBox : AdMoGoAdNetworkAdapter<PBBannerViewDelegate>
{
    NSTimer *timer;
}
+ (AdMoGoAdNetworkType)networkType;

@end
