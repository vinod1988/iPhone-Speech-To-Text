//
//  AudioPlayer.h
//  SpeechToText
//
//  Created by Andrew Shaw on 4/9/12.
//  Copyright (c) 2012 Astrid. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AudioToolbox/AudioToolbox.h>

static const int kNumberBuffers = 3;                              // 1
typedef struct AQPlayerState {
    AudioStreamBasicDescription   mDataFormat;                    // 2
    AudioQueueRef                 mQueue;                         // 3
    AudioQueueBufferRef           mBuffers[kNumberBuffers];       // 4
    AudioFileID                   mAudioFile;                     // 5
    UInt32                        bufferByteSize;                 // 6
    SInt64                        mCurrentPacket;                 // 7
    UInt32                        mNumPacketsToRead;              // 8
    AudioStreamPacketDescription  *mPacketDescs;                  // 9
    bool                          mIsRunning;                     // 10
} AQPlayerState;

@interface AudioPlayer : NSObject {
    AQPlayerState aqData;
}
-(void) setUpNewQueue;
-(void) beginPlayback: (NSString*) fileName;
@end