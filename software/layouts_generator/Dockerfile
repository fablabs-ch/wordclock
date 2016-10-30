FROM python:3.5
MAINTAINER Fabien Dubosson <fabien.dubosson@gmail.com>

RUN apt-get update \
    && apt-get install -y inkscape \
    && rm -rf /var/lib/apt/lists/*

COPY ./ /usr/src/app/
WORKDIR /usr/src/app/

RUN pip install -r requirements.txt

EXPOSE 8000
ENTRYPOINT ["python"]
CMD ["service.py"]
