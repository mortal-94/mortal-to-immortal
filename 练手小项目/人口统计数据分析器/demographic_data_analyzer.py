import pandas as pd


def calculate_demographic_data(print_data=True):
    # 从文件中读取数据
    df = pd.read_csv('adult.data.csv')

    # 这个数据集中每个种族有多少人？ 这应该是一个以种族名称作为索引标签的 Pandas Series。 （race 栏）
    """利用value_counts()方法"""
    race_count = df['race'].value_counts()

    # 男性的平均年龄是多少？
    """df.loc[df['sex'] == 'Male']直接取出所有性别为男性的行，再对其 age 求 mean 便可'"""
    average_age_men = round(df.loc[df['sex'] == 'Male']['age'].mean(), 1)

    # 拥有学士学位的人的百分比是多少？
    """df.loc[df['education'] == 'Bachelors']直接取出所有学士学位的行，用其行数 和 总数据的行数 相除即可"""
    percentage_bachelors = round(df.loc[df['education'] == 'Bachelors'].shape[0] / df.shape[0] * 100, 1)

    # 受过高等教育（Bachelors, Masters, or Doctorate）收入超过 50K 的人占多大比例？
    # 没有受过高等教育的人的收入超过 50K 的比例是多少？

    # 受过高等教育 和 没受过高等教育 的标签
    higher_education = ['Bachelors', 'Masters', 'Doctorate']
    lower_education = [i for i in df['education'].unique() if i not in higher_education]  # unique()返回唯一值

    # 收入超过 50K 的人占多大比例？
    """用 isin() 方法得出对应的 bool值Series，再按题意定位到对应的行"""
    higher_education_rich = df.loc[df['education'].isin(higher_education) & (df['salary'] == '>50K')].shape[0] / \
                            df[df['education'].isin(higher_education)].shape[0]
    higher_education_rich = round(higher_education_rich * 100, 1)
    lower_education_rich = df.loc[(df['education'].isin(lower_education)) & (df['salary'] == '>50K')].shape[0] / \
                           df[df['education'].isin(lower_education)].shape[0]
    lower_education_rich = round(lower_education_rich * 100, 1)

    # 一个人每周最少工作多少小时？
    """这个可以直接求"""
    min_work_hours = df['hours-per-week'].min()

    # 每周工作最少小时数的人中有多少人的工资超过 50K？
    """做法同上"""
    rich_percentage = df.loc[df['hours-per-week'] == min_work_hours & (df['salary'] == '>50K')].shape[0] / \
                      df[df['hours-per-week'] == min_work_hours].shape[0]
    rich_percentage = round(rich_percentage * 100, 1)

    # 哪个国家/地区的收入 >50K 的人口比例最高，该比例是多少？
    """
    df1 = df.loc[df['salary'] == '>50K'] 把收入 >50K 的行拿出来
    df1['native-country'].value_counts() / df['native-country'].value_counts() 利用Series的性质把数量整体索引(国家/地区)对应相除
    用 idxmax()方法 找出最大索引即那个 国家/地区
    """
    df1 = df.loc[df['salary'] == '>50K']
    highest_earning_country = (df1['native-country'].value_counts() / df['native-country'].value_counts()).idxmax()
    """知道了该国家，拿该国家 收入 >50k 的人数 除 该国家的总人数 即可"""
    highest_earning_country_percentage = (
            df1.loc[df1['native-country'] == highest_earning_country].shape[0] /
            df.loc[df['native-country'] == highest_earning_country].shape[0])
    highest_earning_country_percentage = round(highest_earning_country_percentage * 100, 1)

    # 确定印度收入 >50K 的人最受欢迎的职业。
    """同上"""
    top_IN_occupation = \
    df.loc[(df['native-country'] == 'India') & (df['salary'] == '>50K')]['occupation'].value_counts().idxmax()

    # 不要在此行以下修改

    if print_data:
        print("Number of each race:\n", race_count)
        print("Average age of men:", average_age_men)
        print(f"Percentage with Bachelors degrees: {percentage_bachelors}%")
        print(f"Percentage with higher education that earn >50K: {higher_education_rich}%")
        print(f"Percentage without higher education that earn >50K: {lower_education_rich}%")
        print(f"Min work time: {min_work_hours} hours/week")
        print(f"Percentage of rich among those who work fewest hours: {rich_percentage}%")
        print("Country with highest percentage of rich:", highest_earning_country)
        print(f"Highest percentage of rich people in country: {highest_earning_country_percentage}%")
        print("Top occupations in India:", top_IN_occupation)

    return {
        'race_count': race_count,
        'average_age_men': average_age_men,
        'percentage_bachelors': percentage_bachelors,
        'higher_education_rich': higher_education_rich,
        'lower_education_rich': lower_education_rich,
        'min_work_hours': min_work_hours,
        'rich_percentage': rich_percentage,
        'highest_earning_country': highest_earning_country,
        'highest_earning_country_percentage':
            highest_earning_country_percentage,
        'top_IN_occupation': top_IN_occupation
    }


calculate_demographic_data()
