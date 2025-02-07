#pragma once

#include "interfaces/report.hpp"

#include <gmock/gmock.h>

class ReportMock : public interfaces::Report
{
  public:
    ReportMock(const std::string& id)
    {
        using namespace testing;

        ON_CALL(*this, getId).WillByDefault([id] { return id; });
        ON_CALL(*this, getPath).WillByDefault([id] { return "/" + id; });
        EXPECT_CALL(*this, Die).Times(AnyNumber());
    }

    virtual ~ReportMock()
    {
        Die();
    }

    MOCK_METHOD(std::string, getId, (), (override, const));
    MOCK_METHOD(std::string, getPath, (), (override, const));
    MOCK_METHOD(void, updateReadings, (), (override));
    MOCK_METHOD(void, Die, ());
};
