#include "storage/index.hpp"

@protocol MWMMapDownloaderProtocol <NSObject>

- (void)downloadNode:(storage::TCountryId const &)countryId;
- (void)retryDownloadNode:(storage::TCountryId const &)countryId;
- (void)updateNode:(storage::TCountryId const &)countryId;
- (void)deleteNode:(storage::TCountryId const &)countryId;
- (void)cancelNode:(storage::TCountryId const &)countryId;
- (void)showNode:(storage::TCountryId const &)countryId;

@end
