//
//  This code is distributed under the terms and conditions of the MIT license.
//
//  Copyright (c) 2013 Glenn Chiu
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#import <Foundation/Foundation.h>

typedef enum : unsigned char
{
    GCParameterEncodingURL,
    GCParameterEncodingJSON
} GCParameterEncoding;

@protocol GCMultiPartFormData;

@interface GCNetworkRequest : NSMutableURLRequest

+ (instancetype)requestWithURLString:(NSString *)url;

+ (instancetype)requestWithURLString:(NSString *)url
                          HTTPMethod:(NSString *)method
                          parameters:(NSDictionary *)parameters;

+ (instancetype)requestWithURLString:(NSString *)url
                          HTTPMethod:(NSString *)method
                          parameters:(NSDictionary *)parameters
                            encoding:(GCParameterEncoding)encoding;

+ (instancetype)requestWithURLString:(NSString *)url
                          parameters:(NSDictionary *)parameters
            multiPartFormDataHandler:(void(^)(id <GCMultiPartFormData> formData))block;


- (void)setValue:(NSString *)value
  forHeaderField:(NSString *)field;

- (void)setUsername:(NSString *)username
           password:(NSString *)password;

- (void)requestShouldUseHTTPPipelining:(BOOL)shouldUsePipelining;

- (void)setTimeoutIntervalInSeconds:(NSTimeInterval)seconds;

@end

@protocol GCMultiPartFormData <NSObject>

- (void)addTextData:(NSString *)string
               name:(NSString *)name;

- (void)addData:(NSData *)data
           name:(NSString *)name;

- (void)addData:(NSData *)data
           name:(NSString *)name
       filename:(NSString *)filename
       mimeType:(NSString *)mimeType;

- (void)addFileFromPath:(NSString *)filePath
                   name:(NSString *)name;

- (void)addFileFromPath:(NSString *)filePath
                   name:(NSString *)name
               mimeType:(NSString *)mimeType;

@end
